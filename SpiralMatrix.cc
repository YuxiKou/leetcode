/*
  Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
  Given the following matrix:
  [
  [ 1, 2, 3 ],
  [ 4, 5, 6 ],
  [ 7, 8, 9 ]
  ]
  You should return [1,2,3,6,9,8,7,4,5].
*/
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<int> spiralOrder(vector<vector<int> > &matrix)
  {
    vector<int> ret;
    int m = matrix.size();
    if(m == 0) return ret;
    int n = matrix[0].size();
    if(n == 0) return ret;
    int numLayers = ((m < n ? m : n) + 1) / 2;
    for(int i = 0; i < numLayers; ++i) printMatrix(matrix, ret, m, n, i);
    return ret;
  }
  void printMatrix(vector<vector<int> > &matrix, vector<int> &result, int m, int n, int layer)
  {
    for(int i = layer; i < n - layer; ++ i)
    {
      result.push_back(matrix[layer][i]);
    }
    for(int i = layer + 1; i < m - layer; ++ i)
    {
      result.push_back(matrix[i][n-layer-1]);
    }
    if(m == 2 * layer + 1) return;
    for(int i = n - layer - 2; i >= layer; -- i)
    {
      result.push_back(matrix[m-layer-1][i]);
    }
    if(n == 2 * layer + 1) return;
    for(int i = m - layer - 2; i > layer; -- i)
    {
      result.push_back(matrix[i][layer]);
    }
  }
};
