/*
  Given a set of distinct integers, S, return all possible subsets.

  Note:
  Elements in a subset must be in non-descending order.
  The solution set must not contain duplicate subsets.
  For example,
  If S = [1,2,3], a solution is:

  [
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
  ]
*/
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
 public:
  vector<vector<int> > subsets(vector<int> &S)
  {
    int n = S.size();
    vector<vector<int> > ret;
    if(n == 0) return ret;
    int size = pow(2, n);
    sort(S.begin(), S.end());
    for(int i = 0; i < size; ++i)
    {
      vector<int> oneSubset;
      int bits = i;
      for(int j = 0; j < n; ++ j)
      {
        if((bits & 1) == 1) oneSubset.push_back(S[j]);
        bits >>= 1;
      }
      ret.push_back(oneSubset);
    }
    return ret;
  }
};
