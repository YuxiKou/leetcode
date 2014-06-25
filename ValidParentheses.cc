/*
  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
 public:
  bool isValid(string s)
  {
    int length = s.length();
    stack<int> parentheses;
    for (int i = 0 ; i < length ; ++ i )
    {
      switch (s[i])
      {
        case '(': parentheses.push(1); break;
        case '[': parentheses.push(2); break;
        case '{': parentheses.push(3); break;
        case ')':
          if (parentheses.empty() || parentheses.top() != 1) return false;
          parentheses.pop();
          break;
        case ']':
          if (parentheses.empty() || parentheses.top() != 2) return false;
          parentheses.pop();
          break;
        case '}':
          if (parentheses.empty() || parentheses.top() != 3) return false;
          parentheses.pop();
          break;
      }
    }
    if (parentheses.empty()) return true;
    return false;
  }
};
