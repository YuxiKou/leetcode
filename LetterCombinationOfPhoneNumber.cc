/*
  Given a digit string, return all possible letter combinations that the number could represent.
  A mapping of digit to letters (just like on the telephone buttons) is given below.
  Input:Digit string "23"
  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
  Note:
  Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution
{
 public:
  vector<string> letterCombinations(string digits)
  {
    vector<string> result;
    map<char, string> digitLetter;
    digitLetter['2'] = "abc";
    digitLetter['3'] = "def";
    digitLetter['4'] = "ghi";
    digitLetter['5'] = "jkl";
    digitLetter['6'] = "mno";
    digitLetter['7'] = "pqrs";
    digitLetter['8'] = "tuv";
    digitLetter['9'] = "wxyz";

    genComb(digits, digitLetter, result, "", 0);
    return result;
  }
  void genComb(string &digits, map<char, string> &digitLetter, vector<string> &result, string curString, int step)
  {
    if(curString.length() == digits.length())
    {
      result.push_back(curString);
      return;
    }
    string str = digitLetter[digits[step]];
    if(str.length() == 0) return;
    for(int i = 0; i < (int)str.length(); ++i)
    {
      curString.push_back(str[i]);
      genComb(digits, digitLetter, result, curString, step + 1);
      curString.pop_back();
    }
  }
};
