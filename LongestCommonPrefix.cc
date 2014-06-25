/*
  Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  std::string longestCommonPrefix(std::vector<std::string> &strs)
  {
    std::string ret = "";
    if (strs.size() <= 0 ) return "";
    for (std::string::size_type i = 0 ; i < strs[0].length() ; ++ i)
    {
      for (std::vector<std::string>::size_type j = 1; j < strs.size(); ++ j)
      {
        if (strs[j].length() <= i || strs[j][i] != strs[0][i])
          return ret;
      }
      ret += strs[0][i];
    }
    return ret;
  }
};

int main()
{
  Solution sol;
  std::vector<std::string> input;
  input.push_back("abcd");
  input.push_back("abcde");
  input.push_back("abcdef");
  input.push_back("abc");
  input.push_back("abdd");
  std::cout<<sol.longestCommonPrefix(input)<<std::endl;
}
