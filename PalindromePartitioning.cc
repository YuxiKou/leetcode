/*
  Given a string s, partition s such that every substring of the partition is a palindrome.
  Return all possible palindrome partitioning of s.
  For example, given s = "aab",
  Return
  [
  ["aa","b"],
  ["a","a","b"]
  ]
*/
#include <vector>
#include <string>

class Solution
{
 public:
  std::vector<std::vector<std::string> > partition(std::string s)
  {
    std::vector<std::vector<std::string> > result;
    std::vector<std::string> curVector;
    part(result, curVector, s, 0);
    return result;
  }
  void part(std::vector<std::vector<std::string> > &result, std::vector<std::string> &curVector, std::string &inputStr, int step)
  {
    int length = inputStr.length();
    if(length == step)
    {
      result.push_back(curVector);
      return;
    }
    std::string curString = "";
    for(int i = step; i < length; ++ i)
    {
      curString += inputStr[i];
      if(isPalin(curString))
      {
        curVector.push_back(curString);
        part(result, curVector, inputStr, i + 1);
        curVector.pop_back();
      }
    }
  }
  bool isPalin(std::string str)
  {
    int start = 0;
    int end = str.length()-1;
    while(start < end)
    {
      if(str[start++] != str[end--]) return false;
    }
    return true;
  }
};
