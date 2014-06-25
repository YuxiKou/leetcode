/*
  Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
  For example,
  Given n = 3,
  You should return the following matrix:
  [
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
  ]
*/

#include <vector>

class Solution
{
 public:
  std::vector<std::vector<int> > generateMatrix(int n)
  {
    std::vector<std::vector<int> > ret;
    std::vector<int> temp(n, 0);
    int base = 1;
    for(int i = 0 ; i < n ; ++ i)
    {
      ret.push_back(temp);
    }
    for(int i = 0 ; i < ( n + 1 ) / 2  ; ++ i)
    {
      genLayer(ret, i, base);
    }
    return ret;
  }
  void genLayer(std::vector<std::vector<int> > &matrix, int layer, int &base)
  {
    int size = static_cast<int>(matrix.size()) - layer * 2;
    int end = layer + size - 1;
    int total = base + 3 * size - 3;
    for(int i = 0; i < size ; ++ i)
    {
      matrix[layer][layer + i] = base + i;
      matrix[end][layer + i] = total - i;
    }
    total = 4 * size + base - 5;
    for(int i = 1 ; i < size - 1 ; ++ i)
    {
      matrix[layer + i][end] = base + size + i - 1;
      matrix[layer + i][layer] = total - i + 1;
    }
    base += 4 * ( size - 1 );
  }
};
