/*
  Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

  Each number in C may only be used once in the combination.

  Note:
  All numbers (including target) will be positive integers.
  Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
  The solution set must not contain duplicate combinations.
  For example, given candidate set 10,1,2,7,6,1,5 and target 8,
  A solution set is:
  [1, 7]
  [1, 2, 5]
  [2, 6]
  [1, 1, 6]
*/
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
 public:
  vector<vector<int> > combinationSum2(vector<int> &num, int target)
  {
    sort(num.begin(), num.end());
    vector<vector<int> > result;
    vector<int> oneRes;
    combination(result, oneRes, num, 0, target);
    return result;
  }
  void combination(vector<vector<int> > &result, vector<int> &oneRes, vector<int> &num, int step, int target)
  {
    if(target < 0) return;
    if(target == 0) result.push_back(oneRes);
    int n = num.size();
    for(int i = step; i < n; ++ i)
    {
      if(i != step && num[i] == num[i-1]) continue;
      oneRes.push_back(num[i]);
      combination(result, oneRes, num, i + 1, target - num[i]);
      oneRes.pop_back();
    }
  }
};
