/*
  Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
  For example:
  Given binary tree {3,9,20,#,#,15,7},
  3
  / \
  9  20
  /  \
  15   7
  return its level order traversal as:
  [
  [3],
  [9,20],
  [15,7]
  ]
*/

#include <vector>
#include <queue>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  std::vector<std::vector<int> > levelOrder(TreeNode *root)
  {
    //pre-order traversal + BFS + iterate
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
  std::vector<std::vector<int> > levelOrder2(TreeNode *root)
  {
    //pre-order traversal + recursion
    std::vector<std::vector<int> > result;
    levelOrder2Prvt(root, 1, result);
    return result;
  }
  void levelOrder2Prvt(TreeNode *root, int level, std::vector<std::vector<int> > &result)
  {
    if(root == NULL) return;
    if(level > static_cast<int>(result.size()))
    {
      std::vector<int> temp;
      result.push_back(temp);
    }
    result[level-1].push_back(root->val);
    levelOrder2Prvt(root->left, level+1, result);
    levelOrder2Prvt(root->right, level+1, result);
  }
};
