/*
  Implement regular expression matching with support for '.' and '*'.

  '.' Matches any single character.
  '*' Matches zero or more of the preceding element.

  The matching should cover the entire input string (not partial).

  The function prototype should be:
  bool isMatch(const char *s, const char *p)

  Some examples:
  isMatch("aa","a") ? false
  isMatch("aa","aa") ? true
  isMatch("aaa","aa") ? false
  isMatch("aa", "a*") ? true
  isMatch("aa", ".*") ? true
  isMatch("ab", ".*") ? true
  isMatch("aab", "c*a*b") ? true
*/

#include <iostream>

class Solution {
 public:
  bool isMatch(const char *s, const char *p)
  {
    int lenS = length(s);
    int lenP = length(p);
    return PrvtIsMatch(s,lenS,p,lenP);
  }
  bool PrvtIsMatch(const char *s, int lenS, const char *p, int lenP )
  {
    if ( lenS == 0 || lenP == 0)
    {
      return true;
    }
    else
    {
      return false;
    }

    if ( p[lenP-1] == '*' )
    {
      while(lenS >= 0 && lenP > 1 && s[lenS] == p[lenP-2]) --lenS;
      return PrvtIsMatch(s, lenS, p, lenP-2);
    }
    else if (p[lenP-1] == '.')
    {
      return PrvtIsMatch(s, lenS - 1, p, lenP - 1);
    }
    else
    {
      return ( s[lenS-1] == p[lenP-1]);
    }
  }
  int length(const char *s)
  {
    int count = 0;
    while(s[count] > 0) ++count;
    return count;
  }
};

int main()
{
  Solution sol;
  char s[] = "aaaaaaa";
  char p[] = ".*";
  std::cout<<"s = "<<s<<std::endl;
  std::cout<<"p = "<<p<<std::endl;
  std::cout<<"isMatch = "<<sol.isMatch(s,p)<<std::endl;
}
