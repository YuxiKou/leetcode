/*
  Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
  For example,
  Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
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
  std::vector<TreeNode *> generateTrees(int n)
  {
    return *gen(1, n);
  }
  std::vector<TreeNode *>* gen(int start, int end)
  {
    std::vector<TreeNode *> * ret = new std::vector<TreeNode *>();
    if(start > end)
    {
      ret->push_back(NULL);
      return ret;
    }
    for(int i = start; i <= end; ++ i)
    {
      std::vector<TreeNode *> *leftTree = gen(start, i - 1);
      std::vector<TreeNode *> *rightTree = gen(i + 1, end);
      for(int j = 0; j < (int)leftTree->size(); ++ j)
      {
        for(int k = 0; k < (int)rightTree->size(); ++ k)
        {
          TreeNode *head = new TreeNode(i); //for every pair of left and right node, build root node
          head->left = (*leftTree)[j];
          head->right = (*rightTree)[k];
          ret->push_back(head);
        }
      }
    }
    return ret;
  }
};
