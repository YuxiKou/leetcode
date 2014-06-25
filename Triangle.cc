/*
  Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
  For example, given the following triangle
  [
  [2],
  [3,4],
  [6,5,7],
  [4,1,8,3]
  ]
  The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
  Note:
  Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
#include <vector>

using namespace std;

class Solution
{
 public:
  int minimumTotal(vector<vector<int> > &triangle)
  {
    int numRows = triangle.size();
    vector<int> minSum = triangle[numRows - 1];
    for (int i = numRows - 2 ; i >= 0 ; --i)
    {
      for (vector<int>::size_type j = 0 ; j < triangle[i].size(); ++j)
      {
        minSum[j] = triangle[i][j] + min(minSum[j], minSum[j+1]);
      }
    }
    return minSum[0];
  }
};
