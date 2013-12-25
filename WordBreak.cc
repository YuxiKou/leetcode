/*
  Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
  For example, given
  s = "leetcode",
  dict = ["leet", "code"].
  Return true because "leetcode" can be segmented as "leet code".

  Solution:
  One of DP solutions. Given a string s with length n. We use seg(i, j) to indicate whether sub-string t (starting at s[i] and length is j) can be segmented into dictionary words.
  Therefore seg(i, j) = true if
  1): sub-string t is a word in the dictionary;
  or
  2): there is a length k (1 <= k < j) such that both seg(i,k) and seg(i+k, j-k) are true.
  The entire string can be segmented if seg(0, n) is true.

  Here I will change the meaning of seg array to seg(i, j) indicates whether substring t (starting at s[i] and ending at s[j]) ....
*/


#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
 public:
  bool wordBreak(string s, unordered_set<string> &dict)
  {
    int n = s.length();
    if (n == 0) return true;
    vector<bool> temp(n+1, false);
    vector<vector<bool> > seg(n, temp);

    for(int len = 1; len < n + 1; ++ len)
    {
      for(int start = 0; start < n; ++ start)
      {
        string t = s.substr(start, len);
        if(dict.find(t) != dict.end())
        {
          seg[start][len] = true;
          continue;
        }
        for(int k = 1; k < len; ++ k)
        {
          if(seg[start][k] == true && seg[start+k][len-k] == true)
          {
            seg[start][len] = true;
            break;
          }
        }
      }
    }
    return seg[0][n];
  }
};
