/*
  Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
  For "(()", the longest valid parentheses substring is "()", which has length = 2.
  Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s)
  {
    int maxLength = 0;
    int last = -1;
    stack<int> parents;
    for( std::string::size_type i = 0 ; i < s.length() ; ++ i)
    {
      if(s[i]== '(') parents.push(i);
      else if (parents.empty() )
      {
        last = i;
      }
      else
      {
        parents.pop();
        maxLength = max<int>(maxLength, parents.empty() ? i - last : i - parents.top());
      }
    }
    return maxLength ;
  }
};
int main()
{
  Solution sol;
  std::cout<<sol.longestValidParentheses(")(((((()())()()))()(()))(")<<std::endl;
  return 0;
}
