/*
  Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

  Note:
  Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
  The solution set must not contain duplicate quadruplets.
  For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

  A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
 public:
  vector<vector<int> > fourSum(vector<int> &num, int target)
  {
    vector<vector<int> > ret;
    int n = num.size();
    sort(num.begin(), num.end());
    for(int i = 0; i < n - 3; ++ i)
    {
      for (int j = i + 1; j < n - 2; ++j)
      {
        int start = j + 1;
        int end = n - 1;
        int curTarget = target - num[i] - num[j];
        while(start < end)
        {
          if(num[start] + num[end] < curTarget)
          {
            ++start;
            while(start < end && num[start-1] == num[start]) ++start;
          }
          else if(num[start] + num[end] > curTarget)
          {
            --end;
            while(start <end && num[end+1] == num[end]) --end;
          }
          else
          {
            vector<int> oneRes(4);
            oneRes[0] = num[i];
            oneRes[1] = num[j];
            oneRes[2] = num[start];
            oneRes[3] = num[end];
            ret.push_back(oneRes);
            ++start;
            --end;
            while(start < end && num[start-1] == num[start]) ++start;
            while(start <end && num[end+1] == num[end]) --end;
          }
        }
        while(j < n - 2 && num[j] == num[j+1]) ++j;
      }
      while(i < n - 3 && num[i] == num[i+1]) ++i;
    }
    return ret;
  }
};
int main()
{
  Solution sol;
  return 0;
}
