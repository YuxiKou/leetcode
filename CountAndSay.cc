/*
  The count-and-say sequence is the sequence of integers beginning as follows:
  1, 11, 21, 1211, 111221, ...
  1 is read off as "one 1" or 11.
  11 is read off as "two 1s" or 21.
  21 is read off as "one 2, then one 1" or 1211.
  Given an integer n, generate the nth sequence.

  Note: The sequence of integers will be represented as a string.
*/
#include <string>

class Solution {
 public:
  std::string countAndSay(int n)
  {
    if (n < 1) return "";
    std::string ret = "1";
    std::string temp;
    int count = 0;
    for( int i = 1 ; i < n ; ++ i)
    {
      temp = "";
      std::string::size_type j = 0;
      while(j < ret.length())
      {
        count = 0;
        while(j + count< ret.length() && ret[j+count] == ret[j]) ++count;
        temp.append(1, static_cast<char>(count+'0'));
        temp += ret[j];
        j += count;
      }
      ret = temp;
    }
    return ret;
  }
};
