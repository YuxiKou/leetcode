/*
  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

  For example,
  "A man, a plan, a canal: Panama" is a palindrome.
  "race a car" is not a palindrome.

  Note:
  Have you consider that the string might be empty? This is a good question to ask during an interview.

  For the purpose of this problem, we define empty string as valid palindrome.
*/

#include <iostream>
#include <string>

class Solution
{
 public:
  bool isPalindrome(std::string s)
  {
    if (s == "") return true;
    std::string::size_type start = 0;
    std::string::size_type end = s.length() - 1;
    while(start < end)
    {
      int temp1 = formatChar(s[start]);
      if( temp1 < 0 )
      {
        ++ start;
        continue;
      }
      int temp2 = formatChar(s[end]);
      if ( temp2 < 0 )
      {
        -- end;
        continue;
      }
      if( temp1 != temp2) return false;
      ++ start;
      -- end;
    }
    return true;
  }
  int formatChar(const char c)
  {
    if ( (c >= 'a' && c <= 'z' ) || (c >= '0' && c <= '9') )
    {
      return c;
    }
    else if ( c >= 'A' && c <= 'Z')
    {
      return c- ( 'A' - 'a');
    }
    else return -1;
  }
};
