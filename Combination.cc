/*
  Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
  For example,
  If n = 4 and k = 2, a solution is:
  [
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
  ]
*/
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<vector<int> > combine(int n, int k)
  {
    vector<vector<int> > ret;
    vector<int> curValues;
    buildCombination(n, k, 1, curValues, ret);
    return result;
  }
  void buildCombination(int n, int k, int curLevel, vector<int> &curValues, vector<vector<int> > &result)
  {
    if(curValues.size() == k)
    {
      result.push_back(curValues);
      return;
    }
    for(int i = curLevel; i <= n ; ++ i)
    {
      curValues.push_back(i);
      buildCombination(n, k, i + 1, curValues, result);
      curValues.pop_back();
    }
  }
};
