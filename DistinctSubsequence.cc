/*
  Given a string S and a string T, count the number of distinct subsequences of T in S.
  A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
  Here is an example:
  S = "rabbbit", T = "rabbit"
  Return 3.
*/
#include <string>
#include <vector>

using namespace std;

class Solution
{
 public:
  int numDistinct(string S, string T)
  {
    int m = S.size();
    int n = T.size();
    if(m < n) return 0;
    vector<int> matches(n + 1, 0);
    matches[0] = 1;
    for(int i = 1; i < m + 1; ++ i)
    {
      for(int j = n; j > 0; -- j)
      {
        if(S[i-1] == T[j-1]) matches[j] += matches[j-1];
      }
    }
    return matches[n];
  }
};
