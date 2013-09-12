/*
  Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

  Below is one possible representation of s1 = "great":

  great
  /    \
  gr    eat
  / \    /  \
  g   r  e   at
  / \
  a   t
  To scramble the string, we may choose any non-leaf node and swap its two children.

  For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

  rgeat
  /    \
  rg    eat
  / \    /  \
  r   g  e   at
  / \
  a   t
  We say that "rgeat" is a scrambled string of "great".

  Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

  rgtae
  /    \
  rg    tae
  / \    /  \
  r   g  ta  e
  / \
  t   a
  We say that "rgtae" is a scrambled string of "great".

  Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

#include <iostream>
#include <string>

class Solution {
 public:
  bool charCount(std::string s1, std::string s2)
  {
    int* count = new int[26]();
    for (std::string::size_type i = 0 ; i < s1.length() ; ++ i )
    {
      ++ count[s1[i]-'a'];
      -- count[s2[i]-'a'];
    }
    for (std::string::size_type i = 0 ; i < s1.length() ; ++ i )
    {
      if (count[i] != 0 ) return false;
    }
    return true;
  }

  bool isScramble(std::string s1, std::string s2)
  {
    std::string s1Left, s1Right;
    std::string s2Left, s2Right;
    if (s1.length() != s2.length() ) return false;
    if (s1 == s2 ) return true;
    if (!charCount(s1, s2)) return false;
    for (std::string::size_type i = 1 ; i < s1.length(); ++ i )
    {
      s1Left = s1.substr(0,i);
      s2Left = s2.substr(0,i);
      s1Right = s1.substr(i);
      if ( charCount(s1Left, s2Left) && isScramble(s1Left, s2Left))
      {
        s2Right = s2.substr(i);
        if ( isScramble(s1Right, s2Right) ) return true;
      }
      s2Left = s2.substr(s2.length() - i);
      if (charCount(s1Left, s2Left) && isScramble(s1Left, s2Left))
      {
        s2Right = s2.substr(0, s2.length() - i) ;
        if (isScramble(s1Right, s2Right)) return true;
      }
    }
    return false;
  }
};

int main()
{
  Solution sol;
  std::cout<<sol.isScramble("ab", "ba")<<std::endl;
}
