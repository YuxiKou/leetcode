/*
  You are given an n x n 2D matrix representing an image.
  Rotate the image by 90 degrees (clockwise).
  Follow up:
  Could you do this in-place?
*/

#include <vector>

class Solution
{
 public:
  void rotate(std::vector<std::vector<int> > &matrix)
  {
    diagSwap(matrix);
    vertSwap(matrix);
  }
  void diagSwap(std::vector<std::vector<int> > &matrix)
  {
    for( std::vector<std::vector<int> >::size_type i = 0 ; i < matrix.size() ; ++ i)
    {
      for( std::vector<std::vector<int> >::size_type j = 0 ; j < matrix[i].size() - i - 1 ; ++ j)
      {
        std::swap(matrix[i][j], matrix[matrix.size() - j - 1][matrix.size() - i - 1]);
      }
    }
  }
  void vertSwap(std::vector<std::vector<int> > &matrix)
  {
    for( std::vector<std::vector<int> >::size_type i = 0 ; i < matrix.size() / 2 ; ++ i)
    {
      for( std::vector<std::vector<int> >::size_type j = 0 ; j < matrix[i].size() ; ++ j)
      {
        std::swap(matrix[i][j], matrix[matrix.size() - i - 1][j]);
      }
    }
  }
};
