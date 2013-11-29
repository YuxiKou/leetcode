/*
  Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

  The same repeated number may be chosen from C unlimited number of times.

  Note:
  All numbers (including target) will be positive integers.
  Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
  The solution set must not contain duplicate combinations.
  For example, given candidate set 2,3,6,7 and target 7,
  A solution set is:
  [7]
  [2, 2, 3]
*/
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<vector<int> > combinationSum(vector<int> &candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > result;
    vector<int> oneRes;
    combination(result, oneRes, candidates, 0, target);
    return result;
  }
  void combination(vector<vector<int> > &result, vector<int> &oneRes, vector<int> &num, int step, int target)
  {
    if(target < 0) return;
    if(target == 0) result.push_back(oneRes);
    int n = num.size();
    for(int i = step; i < n; ++ i)
    {
      oneRes.push_back(num[i]);
      combination(result, oneRes, num, i , target - num[i]);
      oneRes.pop_back();
    }
  }
};
