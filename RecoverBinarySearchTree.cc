/*
  Two elements of a binary search tree (BST) are swapped by mistake.
  Recover the tree without changing its structure.
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
  void recoverTree(TreeNode *root) //Morris Traversal
  {
    TreeNode *curNode = root;
    TreeNode *fail1 = NULL, *fail2 = NULL;
    TreeNode *pre = NULL;
    while(curNode != NULL)
    {
      if(curNode->left == NULL)
      {
        if(pre != NULL && pre->val > curNode->val)
        {
          if(fail1 == NULL) fail1 = pre;
          fail2 = curNode;
        }
        pre = curNode;
        curNode = curNode->right;
      }
      else
      {
        TreeNode *preNode = curNode->left; //not NULL
        while(preNode->right != NULL && preNode->right != curNode) preNode = preNode->right;
        if(preNode->right == NULL)
        {
          preNode->right = curNode;
          curNode = curNode->left;
        }
        else
        {
          preNode->right = NULL;
          if(pre != NULL && pre->val > curNode->val)
          {
            if(fail1 == NULL) fail1 = pre;
            fail2 = curNode;
          }
          pre = curNode;
          curNode = curNode->right;
        }
      }
    }
    if(fail1 != NULL && fail2 != NULL) std::swap(fail1->val, fail2->val);
  }
};
