/*
  Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/
#include <vector>
#include <stack>

using namespace std;

class Solution
{
 public:
  int maximalRectangle(vector<vector<char> > &matrix)
  {
    int m = matrix.size();
    if(m == 0) return 0;
    int n = matrix[0].size();
    if(n == 0) return 0;
    int maxArea = 0;
    for(int i = 0; i < m; ++i)
    {
      vector<int> oneRow(n, 0);
      for(int j = 0; j < n; ++ j)
      {
        if(oneRow[j] > 0) --oneRow[j];
        else
        {
          for(int k = i; k < m && matrix[k][j] == '1'; ++ k) ++oneRow[j];
        }
      }
      int area = largestRectangleArea(oneRow);
      maxArea = max(area, maxArea);
    }
    return maxArea;
  }
  int largestRectangleArea(std::vector<int> &height)
  {
    std::stack<int> incHeight;
    int maxArea = 0;
    height.push_back(0);
    for(std::vector<int>::size_type i = 0 ; i < height.size(); ++ i)
    {
      if (incHeight.empty() || height[incHeight.top()] < height[i]) incHeight.push(i);
      else
      {
        int h = incHeight.top();
        incHeight.pop();
        maxArea = max<int>(maxArea, height[h] * ( incHeight.empty() ? i : i - incHeight.top() - 1));
        -- i;
      }
    }
    return maxArea;
  }
};
