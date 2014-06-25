/*
  Given a collection of numbers, return all possible permutations.
  For example,
  [1,2,3] have the following permutations:
  [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
*/
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<vector<int> > permute(vector<int> &num)
  {
    vector<vector<int> > result;
    if(num.size() == 0) return result;
    vector<int> oneResult;
    vector<bool> visited(num.size(), false);
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
        visited[i] = true;
        oneResult.push_back(num[i]);
        permutePrvt(result, oneResult, visited, num);
        oneResult.pop_back();
        visited[i] = false;
      }
    }
  }
};
