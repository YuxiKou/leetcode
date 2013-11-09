/*
  Given a binary tree, return the preorder traversal of its nodes' values.
  For example:
  Given binary tree {1,#,2,3},
  1
  \
  2
  /
  3
  return [1,2,3].

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
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> ret;
    stack<TreeNode*> TNStack ;
    TreeNode *curNode;
    if(root == NULL) return ret;
    TNStack.push(root);
    while(!TNStack.empty())
    {
      curNode = TNStack.top();
      TNStack.pop();
      ret.push_back(curNode->val);
      if(curNode->right != NULL) TNStack.push(curNode->right);
      if(curNode->left != NULL) TNStack.push(curNode->left);
    }
    return ret;
  }
};
