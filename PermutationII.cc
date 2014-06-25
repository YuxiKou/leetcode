/*
  Given a collection of numbers that might contain duplicates, return all possible unique permutations.
  For example,
  [1,1,2] have the following unique permutations:
  [1,1,2], [1,2,1], and [2,1,1].
*/
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<vector<int> > permuteUnique(vector<int> &num)
  {
    vector<vector<int> > result;
    if(num.size() == 0) return result;
    vector<int> oneResult;
    vector<bool> visited(num.size(), false);
    sort(num.begin(), num.end());
    permutePrvt(result, oneResult, visited, num);
    return result;
  }
  void permutePrvt(vector<vector<int> > &result, vector<int> &oneResult, vector<bool> &visited, vector<int> &num)
  {
    if(oneResult.size() == num.size())
    {
      result.push_back(oneResult);
      return;
    }
    for(vector<int>::size_type i = 0; i < num.size(); ++i)
    {
      if(visited[i] == false)
      {
        if(i > 0 && num[i] == num[i-1] && visited[i-1] == false) continue;
        visited[i] = true;
        oneResult.push_back(num[i]);
        permutePrvt(result, oneResult, visited, num);
        oneResult.pop_back();
        visited[i] = false;
      }
    }
  }
};
