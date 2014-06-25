/*
  A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
  The robot can only move either down or right at any point in time.
  The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
  How many possible unique paths are there?
*/

#include <vector>

class Solution
{
 public:
  int uniquePaths(int m, int n)
  {
    std::vector<int> oneRow(n,0);
    std::vector<std::vector<int> > ret;
    for(int i = 0 ; i < m ; ++ i)
    {
      ret.push_back(oneRow);
      for(int j = 0 ; j < n ; ++ j)
      {
        if(i == 0) ret[0][j] = 1;
        else ret[i][j] = (j == 0 ? 1 : ret[i-1][j] + ret[i][j-1]);
      }
    }
    return ret[m-1][n-1];
  }
};
