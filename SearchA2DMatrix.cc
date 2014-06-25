/*
  Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

  Integers in each row are sorted from left to right.
  The first integer of each row is greater than the last integer of the previous row.
  For example,

  Consider the following matrix:

  [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
  ]
  Given target = 3, return true.
*/
#include <vector>

class Solution
{
 public:
  bool searchMatrix(std::vector<std::vector<int> > &matrix, int target)
  {
    if(matrix.size() < 1 || matrix[0].size() < 1 || target < matrix[0][0]) return false;
    std::vector<int>::size_type i = 0, j =0;
    while(i < matrix.size() && matrix[i][0] <= target) ++ i;
    --i;
    while(j < matrix[i].size())
    {
      if( matrix[i][j] > target) return false;
      else if( matrix[i][j] == target) return true;
      ++j;
    }
    return false;
  }
};
