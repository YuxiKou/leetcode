/*
  Given a string s, partition s such that every substring of the partition is a palindrome.
  Return the minimum cuts needed for a palindrome partitioning of s.
  For example, given s = "aab",
  Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
#include <vector>
#include <string>

class Solution
{
 public:
  int minCut(std::string s)
  {
    int length = s.length();
    std::vector<bool> temp(length, false);
    std::vector<std::vector<bool> > isPalin(length, temp);
    std::vector<int> minCut(length, 0);
    for(int i = length - 1; i >= 0; --i)
    {
      for(int j = i; j < length; ++j)
      {
        if(s[i] == s[j] && (j - i < 2 || isPalin[i+1][j-1])) isPalin[i][j] = true;
      }
    }
    for(int i = 0; i < length; ++ i)
    {
      int min = length;
      if(isPalin[0][i]) minCut[i] = 0;
      else
      {
        for(int j = 0; j < i; ++ j)
        {
          if(isPalin[j+1][i] && minCut[j] + 1 < min) min = minCut[j] + 1;
        }
        minCut[i] = min;
      }
    }
    return minCut[length-1];
  }
};
