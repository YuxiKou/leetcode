/*
  Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
  Note: You can only move either down or right at any point in time.
*/

#include <vector>

class Solution
{
 public:
  int minPathSum(std::vector<std::vector<int> > &grid)
  {
    int m = grid.size();
    if(m == 0) return 0;
    int n = grid[0].size();
    std::vector<std::vector<int> > pathSum;
    for( int i = 0 ; i < m ; ++ i)
    {
      std::vector<int> oneRow(n, 0);
      for( int j = 0 ; j < n ; ++ j)
      {
        if( i == 0 ) oneRow[j] = (j > 0 ? oneRow[j-1] : 0 )+ grid[0][j];
        else if( j == 0) oneRow[0] = pathSum[i-1][0] + grid[i][0];
        else oneRow[j] = std::min(pathSum[i-1][j], oneRow[j-1]) + grid[i][j];
      }
      pathSum.push_back(oneRow);
    }
    return pathSum[m-1][n-1];
  }
};
