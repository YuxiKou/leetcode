/*
  Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

  An example is the root-to-leaf path 1->2->3 which represents the number 123.

  Find the total sum of all root-to-leaf numbers.

  For example,

  1
  / \
  2   3
  The root-to-leaf path 1->2 represents the number 12.
  The root-to-leaf path 1->3 represents the number 13.

  Return the sum = 12 + 13 = 25.
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
  int sumNumbers(TreeNode *root)
  {
    long long sum = 0;
    sumPrvt(root, 0, sum);
    return sum;
  }
  void sumPrvt(TreeNode *root, long long prefix, long long &sum)
  {
    if( root == NULL ) return;
    prefix = prefix * 10 + root->val;
    if( root->left == NULL && root->right == NULL)
    {
      sum += prefix;
      return;
    }
    sumPrvt(root->left, prefix, sum);
    sumPrvt(root->right, prefix, sum);
  }
};


