/*
  Evaluate the value of an arithmetic expression in Reverse Polish Notation.
  Valid operators are +, -, *, /. Each operand may be an integer or another expression.
  Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
#include <vector>
#include <string>
#include <stack>
#include <limits>
#include <iostream>

using namespace std;

const int min_int = std::numeric_limits<int>::min();
const int max_int = std::numeric_limits<int>::max();

class Solution
{
 public:
  int evalRPN(vector<string> &tokens)
  {
    stack<int> operand;
    for(int i = 0; i < (int)tokens.size(); ++ i)
    {
      string str = tokens[i];
      int left, right;
      if(isOperator(str))
      {
        right = operand.top();
        operand.pop();
        left = operand.top();
        operand.pop();
        if(str[0] == '+') left += right;
        else if(str[0] == '-') left -= right;
        else if(str[0] == '*') left *= right;
        else if(str[0] == '/') left /= right;
        operand.push(left);
      }
      else if(isOperand(str))
      {
        operand.push(atoi(str));
      }
      else return 0;
    }
    if(!operand.empty()) return operand.top();
    else return 0;
  }
  bool isOperand(string &str)
  {
    return (str.length() > 1 || (str[0] <= '9' && str[0] >= '0'));
  }
  bool isOperator(string &str)
  {
    return (str.length() == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/'));
  }
  int atoi(string str)
  {
    long long ret = 0;
    int i = 0;
    int signSet = 0;
    while( str[i] > 0 )
    {
      if ( signSet == 0 )
      {
        if ( str[i] == '-' || str[i] == '+' || str[i] == ' ')
        {
          if (str[i] == '-') signSet = -1;
          else if (str[i] == '+') signSet = 1;
          ++ i;
          continue;
        }
      }
      if (str[i] >= '0' && str[i] <= '9')
      {
        if (signSet == 0 ) signSet = 1;
        ret = ret * 10;
        ret += (str[i] - '0');
        if (signSet * ret > max_int) return max_int;
        else if (signSet * ret < min_int) return min_int;
      }
      else break;
      ++ i;
    }
    return ret * signSet;
  }
};
int main()
{
  Solution sol;
  vector<string> input;
  input.push_back("18");
  int result = sol.evalRPN(input);
  cout<<result<<endl;
  return 0;
}
