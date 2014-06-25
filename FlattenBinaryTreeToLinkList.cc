/*
  Given a binary tree, flatten it to a linked list in-place.
  For example,
  Given
  1
  / \
  2   5
  / \   \
  3   4   6
  The flattened tree should look like:
  1
  \
  2
  \
  3
  \
  4
  \
  5
  \
  6
  If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
*/
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
  void flatten(TreeNode *root)
  {
    stack<TreeNode*> TNStack;
    TreeNode *curNode;
    TreeNode *end = NULL;
    if(root == NULL) return;
    TNStack.push(root);
    while(!TNStack.empty())
    {
      curNode = TNStack.top();
      TNStack.pop();
      if(end != NULL)
      {
        end->right = curNode;
        end->left = NULL;
      }
      end = curNode;
      if(curNode->right != NULL) TNStack.push(curNode->right);
      if(curNode->left != NULL) TNStack.push(curNode->left);
    }
  }
};
