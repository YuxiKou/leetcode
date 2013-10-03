/*
  Given a binary tree, determine if it is a valid binary search tree (BST).
  Assume a BST is defined as follows:
  The left subtree of a node contains only nodes with keys less than the node's key.
  The right subtree of a node contains only nodes with keys greater than the node's key.
  Both the left and right subtrees must also be binary search trees.
*/

#include <iostream>
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
  bool isValidBST(TreeNode *root)
  {
    return isValid(root, INT_MIN, INT_MAX);
  }
  bool isValid(TreeNode *root, int min, int max)
  {
    if(root == NULL) return true;
    if(root->val <= min || root->val >= max) return false;
    return isValid(root->left, min, root->val) && isValid(root->right, root->val, max);
  }
};
