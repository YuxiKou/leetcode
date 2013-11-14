/*
  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
  For example, given n = 3, a solution set is:
  "((()))", "(()())", "(())()", "()(())", "()()()"
*/
#include <vector>
#include <string>

using namespace std;

class Solution
{
 public:
  vector<string> generateParenthesis(int n)
  {
    vector<string> ret;
    generateParenthesisPrivate(ret, "", n, n);
    return ret;
  }
  void generateParenthesisPrivate(vector<string> &allParent, string prefix, int leftParent, int rightParent)
  {
    if(leftParent == 0)
    {
      for(int i = 0; i < rightParent; ++i)
      {
        prefix += ')';
      }
      allParent.push_back(prefix);
      return;
    }
    if(leftParent > rightParent) return;
    else if(leftParent == rightParent)
    {
      generateParenthesisPrivate(allParent, prefix + '(', leftParent - 1, rightParent);
    }
    else
    {
      generateParenthesisPrivate(allParent, prefix + '(', leftParent - 1, rightParent);
      generateParenthesisPrivate(allParent, prefix + ')', leftParent, rightParent - 1);
    }
  }
};
