/*
  Given a binary tree, return the postorder traversal of its nodes' values.
  For example:
  Given binary tree {1,#,2,3},
  1
  \
  2
  /
  3
  return [3,2,1].
  Note: Recursive solution is trivial, could you do it iteratively?
*/
#include <stack>
#include <vector>

using namespace std;

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
  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> ret;
    stack<TreeNode*> TNStack;
    TreeNode *curNode;
    if(root == NULL) return ret;
    TNStack.push(root);
    while(!TNStack.empty())
    {
      curNode = TNStack.top();
      if(curNode->left == NULL && curNode->right == NULL)
      {
        ret.push_back(curNode->val);
        TNStack.pop();
      }
      else
      {
        if(curNode->right != NULL)
        {
          TNStack.push(curNode->right);
          curNode->right = NULL;
        }
        if(curNode->left != NULL)
        {
          TNStack.push(curNode->left);
          curNode->left = NULL;
        }
      }
    }
    return ret;
  }
};
