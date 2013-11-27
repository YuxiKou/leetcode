/*
  Given a collection of integers that might contain duplicates, S, return all possible subsets.

  Note:
  Elements in a subset must be in non-descending order.
  The solution set must not contain duplicate subsets.
  For example,
  If S = [1,2,2], a solution is:

  [
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
  ]
*/
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<vector<int> > subsetsWithDup(vector<int> &S)
  {
    vector<vector<int> > result;
    if(S.size() == 0) return result;
    vector<int> curResult;
    sort(S.begin(), S.end());
    subset(S, 0, result, curResult);
    return result;
  }
  void subset(vector<int> &S, int step, vector<vector<int> > &result, vector<int> &curResult)
  {
    result.push_back(curResult);
    int n = S.size();
    for(int i = step; i < n; ++ i)
    {
      if(i != step && S[i] == S[i-1]) continue;
      curResult.push_back(S[i]);
      subset(S, i + 1, result, curResult);
      curResult.pop_back();
    }
  }
};
