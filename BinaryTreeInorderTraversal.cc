/*
  Given a binary tree, return the inorder traversal of its nodes' values.

  For example:
  Given binary tree {1,#,2,3},
  1
  \
  2
  /
  3
  return [1,3,2].

  Note: Recursive solution is trivial, could you do it iteratively?
*/
#include <vector>
#include <stack>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
 public:
  std::vector<int> inorderTraversal(TreeNode *root)
  {
    std::stack<TreeNode*> myStack;
    TreeNode *curNode = root;
    std::vector<int> ret;
    while(true)
    {
      if(curNode)
      {
        myStack.push(curNode);
        curNode = curNode->left;
      }
      else
      {
        if(myStack.empty())
        {
          break;
        }
        else
        {
          curNode = myStack.top();
          myStack.pop();
          ret.push_back(curNode->val);
          curNode = curNode->right;
        }
      }
    }
    return ret;
  }
};
