/*
  Given a string S, find the longest palindromic substring in S.
  You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s)
  {
    int length = s.length();
    int mx = 0;
    int *aryLen;
    int center = 0;
    int maxLen = 0;
    int maxStart = 0;
    string str,ret;

    for ( int i = 0 ; i < length ; ++ i )
    {
      str += "#";
      str += s[i];
    }
    str += "#";

    length = str.length();
    aryLen = new int[length];

    for ( int i = 0 ; i < length ; ++ i )
    {
      aryLen[i] = mx > i ? min( aryLen[center * 2 - i], mx - i ) : 1;
      while( i - aryLen[i] >= 0 && \
             i + aryLen[i] < length && \
             str[i - aryLen[i]] == str[i + aryLen[i]]) ++ aryLen[i];
      if( mx < i + aryLen[i])
      {
        mx = i + aryLen[i] - 1;
        if (maxLen < aryLen[i])
        {
          maxLen = aryLen[i];
          maxStart = i - aryLen[i] + 1;
        }
        center = i;
      }

    }
    ret = s.substr(maxStart / 2, maxLen - 1);
    return ret;
  }
};

int main()
{
  string s = "aaabcbabc";
  Solution sol;
  cout<<sol.longestPalindrome(s)<<endl;
}
