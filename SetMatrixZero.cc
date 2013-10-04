/*
  Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
  Follow up:
  Did you use extra space?
  A straight forward solution using O(mn) space is probably a bad idea.
  A simple improvement uses O(m + n) space, but still not the best solution.
  Could you devise a constant space solution?
*/

#include <vector>

class Solution
{
 public:
  void setZeroes(std::vector<std::vector<int> > &matrix)
  {
    bool ColZero = false, RowZero = false;
    if(matrix.size() == 0 || matrix[0].size() == 0) return;
    int m = static_cast<int>(matrix.size());
    int n = static_cast<int>(matrix[0].size());
    for(int i = 0 ; i < m ; ++ i)
    {
      if(matrix[i][0] == 0)
      {
        ColZero = true;
        break;
      }
    }

    for(int i = 0 ; i < n ; ++ i)
    {
      if(matrix[0][i] == 0)
      {
        RowZero = true;
        break;
      }
    }

    for(int i = 1 ; i < m ; ++ i)
    {
      for(int j = 1 ; j < n ; ++ j)
      {
        if(matrix[i][j] == 0)
        {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    for(int i = 1 ; i < m ; ++ i)
    {
      for(int j = 1 ; j < n ; ++ j)
      {
        if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
      }
    }
    if(ColZero) for(int i = 0 ; i < m ; ++ i) matrix[i][0] = 0;
    if(RowZero) for(int j = 0 ; j < n ; ++ j) matrix[0][j] = 0;
  }
};
