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

using namespace std;

const int min_int = std::numeric_limits<int>::min();
const int max_int = std::numeric_limits<int>::max();

class Solution
{
 public:
  int evalRPN(vector<string> &tokens)
  {
    int n = tokens.size();
    if(n == 0) return 0;
    stack<int> operand;
    for(int i = 0; i < n; ++ i)
    {
      string str = tokens[i];
      int left, right;
      if(isOperand(str))
      {
        right = operand.top();
        operand.pop();
        left = operand.top();
        operand.pop();
        switch(str[0])
        {
          case '+':
            left += right;
            break;
          case '-':
            left -= right;
            break;
          case '*':
            left *= right;
            break;
          case '/':
            left /= right;
            break;
        }
        operand.push(left);
      }
      else if(isOperator(str))
      {
        operand.push(atoi(str));
      }
      else return 0;
    }
    return operand.top();
  }
  bool isOperand(string str)
  {
    return (str[0] <= '9' && str[0] >= '0');
  }
  bool isOperator(string str)
  {
    return (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/');
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
