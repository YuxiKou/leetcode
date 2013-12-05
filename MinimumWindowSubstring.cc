/*
  Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
  For example,
  S = "ADOBECODEBANC"
  T = "ABC"
  Minimum window is "BANC".

  Note:
  If there is no such window in S that covers all characters in T, return the emtpy string "".

  If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/
#include <string>
#include <map>

class Solution
{
 public:
  std::string minWindow(std::string S, std::string T)
  {
    int sLen = S.size();
    int tLen = T.size();
    if(sLen == 0 || tLen == 0 || sLen < tLen) return "";
    std::map<char, int> target;
    std::map<char, int> found;
    for(int i = 0; i < tLen; ++ i) ++target[T[i]];
    int foundChar = 0;
    std::string minString = "";
    for(int start = 0, end = 0; end < sLen; ++ end)
    {
      if(target[S[end]] == 0) continue;
      if(found[S[end]] < target[S[end]]) ++foundChar;
      ++found[S[end]];
      if(foundChar == tLen)
      {
        while(target[S[start]] == 0 || found[S[start]] > target[S[start]])
        {
          if(found[S[start]] > target[S[start]]) --found[S[start]];
          ++start;
        }
        int len = end - start + 1;
        if(minString.empty() || len < (int)minString.size()) minString = S.substr(start, len);
      }
    }
    return minString;
  }
};
