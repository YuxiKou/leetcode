/*
  Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
  Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
  The largest rectangle is shown in the shaded area, which has area = 10 unit.
  For example,
  Given height = [2,1,5,6,2,3],
  return 10.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
class Solution
{
 public:
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
int main()
{
  std::vector<int> height;
  height.push_back(2);
  height.push_back(1);
  height.push_back(5);
  height.push_back(6);
  height.push_back(2);
  height.push_back(3);
  Solution sol;
  std::cout<<sol.largestRectangleArea(height)<<std::endl;
}
