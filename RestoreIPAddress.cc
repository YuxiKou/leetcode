/*
  Given a string containing only digits, restore it by returning all possible valid IP address combinations.
  For example:
  Given "25525511135",
  return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
#include <vector>
#include <string>

class Solution
{
 public:
  std::vector<std::string> restoreIpAddresses(std::string s)
  {
    std::vector<std::string> ret;
    std::string oneStr;
    parse(ret, oneStr, s, 0, 0);
    return ret;
  }
  std::string parse(std::vector<std::string> &result, std::string &oneStr, std::string, int start, int piece)
  {

  }
};
