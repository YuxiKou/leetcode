/*
  Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
  For example:
  Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
 return its bottom-up level order traversal as:
 [
 [15,7]
 [9,20],
 [3],
 ]
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

#include <vector>

class Solution
{
 public:
  std::vector<std::vector<int> > levelOrderBottom(TreeNode *root)
  {
    std::vector<std::vector<int> > ret = levelOrder(root);
    std::reverse(ret.begin(), ret.end());
    return ret;
  }
  std::vector<std::vector<int> > levelOrder(TreeNode *root)
  {
    //pre-order traversal + BFS
    int level = 0, count = 1;
    std::queue<TreeNode *> TreeList;
    std::vector<std::vector<int> > ret;
    std::vector<int> temp;
    TreeNode * curNode;
    if (root == NULL) return ret;
    TreeList.push(root);
    while(!TreeList.empty())
    {
      curNode = TreeList.front();
      TreeList.pop();
      if(static_cast<int>(ret.size()) <= level) ret.push_back(temp);
      ret[level].push_back(curNode->val);
      if(curNode->left != NULL) TreeList.push(curNode->left);
      if(curNode->right != NULL) TreeList.push(curNode->right);
      if (--count == 0)
      {
        level ++;
        count = TreeList.size();
      }
    }
    return ret;
  }
};
