/*
  Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

#include <iostream>
#include <vector>

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
  TreeNode *sortedArrayToBST(std::vector<int> &num)
  {
    if(num.size() == 0 ) return NULL;
    return buildTree(num, 0, num.size() - 1);
  }
  TreeNode *buildTree(std::vector<int> &num, std::vector<int>::size_type start,  std::vector<int>::size_type end)
  {
    std::vector<int>::size_type mid = (start + end) / 2;
    TreeNode *ret = new TreeNode(num[mid]);
    if (start < mid) ret->left = buildTree(num, start, mid - 1);
    if (end > mid) ret->right = buildTree(num, mid + 1, end);
    return ret;
  }
};
