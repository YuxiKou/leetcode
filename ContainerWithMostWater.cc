/*
  Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

  Note: You may not slant the container.
*/

#include <iostream>
#include <vector>

class Solution {
 public:
  int maxArea(std::vector<int> &height)
  {
    int i = 0;
    int j = height.size() - 1;
    int maxArea = 0;
    int area;
    while( j > i)
    {
      area = ( j - i ) * std::min(height[i],height[j]);
      if ( area > maxArea)
      {
        maxArea = area;
      }
      if ( height[j] > height[i] ) ++ i;
      else --j;
    }
    return maxArea;
  }
};

int main()
{
  Solution sol;
  std::vector<int> height;

  height.push_back(5);
  height.push_back(6);
  height.push_back(7);
  height.push_back(3);
  height.push_back(4);
  height.push_back(5);
  height.push_back(7);
  sol.maxArea(height);
}
