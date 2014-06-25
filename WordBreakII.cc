/*
  Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
  Return all such possible sentences.

  For example, given
  s = "catsanddog",
  dict = ["cat", "cats", "and", "sand", "dog"].

  A solution is ["cats and dog", "cat sand dog"].
*/

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
 public:
  vector<string> wordBreak(string s, unordered_set<string> &dict)
  {
    vector<string> result;
    int n = s.length();
    vector<bool> seg(n + 1, true);
    dfs(s, dict, result, "", 0, n, seg);
    return result;
  }
  void dfs(const string s,
           const unordered_set<string> &dict,
           vector<string> &result,
           const string &curStr,
           const int &start,
           const int &n,
           vector<bool> &seg)
  {
    if (start == n)
    {
      result.push_back(curStr.substr(0, curStr.length() - 1));
      return;
    }
    for(int i = start + 1; i < n + 1; ++ i)
    {
      string t = s.substr(start, i - start);
      if(seg[i+1] == true && dict.find(t) != dict.end())
      {
        string temp = curStr + t + " ";
        int size = result.size();
        dfs(s, dict, result, temp, i, n, seg);
        if((int)result.size() == size) seg[i+1] = false;
      }
    }
  }
};
