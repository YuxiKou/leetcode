/*
  Given a binary tree, find the maximum path sum.
  The path may start and end at any node in the tree.
  For example:
  Given the below binary tree,
       1
      / \
     2   3
  Return 6.
*/
#include <iostream>
#include <algorithm>
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
  int maxPathSum(TreeNode *root)
  {
    int res = INT_MIN;
    maxPath(root, res);
    return res;
  }
  int maxPath(TreeNode *root, int &res)
  {
    if(root == NULL) return 0;
    int l = maxPath(root->left,res);
    int r = maxPath(root->right,res);
    int sum = std::max(root->val, std::max(l, r) + root->val);
    res = std::max(std::max(res, l + r + root->val), sum);
    return sum;
  }
};
