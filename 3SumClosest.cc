/*
  Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
  For example, given array S = {-1 2 1 -4}, and target = 1.
  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include <vector>
#include <limits>

using namespace std;

class Solution
{
 public:
  int threeSumClosest(vector<int> &num, int target)
  {
    int size = num.size();
    if(size < 3) return 0;
    sort(num.begin(), num.end());
    int bestSum = num[0] + num[1] + num[2];
    for(int i = 0; i < size; ++i)
    {
      int start = i + 1;
      int end = size - 1;
      while(start < end)
      {
        int sum = num[i] + num[start] + num[end];
        if(sum == target) return target;
        if(abs(target - sum) < abs(target - bestSum)) bestSum = sum;
        if(target < sum) --end;
        else ++ start;
      }
    }
    return bestSum;
  }
  inline int abs(int input)
  {
    return input > 0 ? input : -input;
  }
};
