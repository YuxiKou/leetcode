/*
  Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
  For example:
  Given binary tree {3,9,20,#,#,15,7},
  3
  / \
  9  20
  /  \
  15   7
  return its zigzag level order traversal as:
  [
  [3],
  [20,9],
  [15,7]
  ]
*/
#include <vector>
#include <stack>

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
  vector<vector<int> > zigzagLevelOrder(TreeNode *root)
  {
    //pre-order traversal + BFS + iterate
    int level = 0, count = 1;
    std::stack<TreeNode *> treeList;
    std::stack<TreeNode *> nextLevel;
    std::vector<std::vector<int> > ret;
    std::vector<int> temp;
    TreeNode * curNode;
    if (root == NULL) return ret;
    treeList.push(root);
    while(!treeList.empty())
    {
      curNode = treeList.top();
      treeList.pop();
      if(static_cast<int>(ret.size()) <= level) ret.push_back(temp);
      ret[level].push_back(curNode->val);
      if(level % 2 == 0)
      {
        if(curNode->left != NULL) nextLevel.push(curNode->left);
        if(curNode->right != NULL) nextLevel.push(curNode->right);
      }
      else
      {
        if(curNode->right != NULL) nextLevel.push(curNode->right);
        if(curNode->left != NULL) nextLevel.push(curNode->left);
      }
      if(treeList.empty())
      {
        ++level;
        swap(treeList, nextLevel);
      }
    }
    return ret;
  }
};
