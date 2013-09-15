/*
  Given preorder and inorder traversal of a tree, construct the binary tree.
  Note:
  You may assume that duplicates do not exist in the tree.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <algorithm>
#include <vector>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
        _______7______
       /              \
    __10__          ___2
   /      \        /
   4       3      _8
            \    /
             1  11
  The preorder and inorder traversals for the binary tree above is:
  preorder = {7,10,4,3,1,2,8,11}
  inorder = {4,10,3,1,7,11,8,2}
*/
class Solution
{
 public:
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
  {
    return buildTreeHelper(preorder, 0, preorder.size() , inorder,  0);
  }
  TreeNode *buildTreeHelper(std::vector<int> &preorder, std::vector<int>::size_type preStart, std::vector<int>::size_type length, \
                            std::vector<int> &inorder,  std::vector<int>::size_type inStart)
  {
    if (length == 0 ) return NULL;
    if (preStart > preorder.size() - length ) return NULL;
    if (inStart > inorder.size() - length ) return NULL;
    TreeNode *ret = new TreeNode(preorder[preStart]);
    int index = findIndex(inorder, inStart, length, preorder[preStart]);
    ret->left = buildTreeHelper(preorder, preStart + 1, index - inStart, inorder, inStart);
    ret->right = buildTreeHelper(preorder, preStart + 1 + index - inStart, length - index + inStart - 1, inorder, index + 1);
    return ret;
  }
  int findIndex(std::vector<int> array, std::vector<int>::size_type start, std::vector<int>::size_type length, int target)
  {
    for (std::vector<int>::size_type i = 0; i < length && start + i < array.size(); ++ i )
    {
      if (array[start + i] == target) return start + i;
    }
    return -1;
  }
  void preOrderTrav(TreeNode *root)
  {
    if(root == NULL) return;
    std::cout<<root->val<<", ";
    preOrderTrav(root->left);
    preOrderTrav(root->right);
  }
};
int main()
{
  int a[] = {7,10,4,3,1,2,8,11};
  int b[] = {4,10,3,1,7,11,8,2};
  Solution sol;
  std::vector<int> preorder(a, a + sizeof(a) / sizeof(int));
  std::vector<int> inorder(b, b + sizeof(a) / sizeof(int));
  TreeNode *root = sol.buildTree(preorder, inorder);
  sol.preOrderTrav(root);
  return 0;
}
