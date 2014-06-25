/*
  Given a binary tree
  struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
  }
  Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

  Initially, all next pointers are set to NULL.

  Note:

  You may only use constant extra space.
  You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
  For example,
  Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
    After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
 */

#include <iostream>
#include <stack>

struct TreeLinkNode
{
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
 public:
  void connect(TreeLinkNode *root)
  {
    TreeLinkNode *curNode;
    TreeLinkNode *leftMost = root;
    while(leftMost != NULL)
    {
      curNode = leftMost;
      while(curNode != NULL)
      {
        if(curNode->left != NULL)
        {
          curNode->left->next = curNode->right;
        }
        if(curNode->right != NULL && curNode->next != NULL)
        {
          curNode->right->next = curNode->next->left;
        }
        curNode = curNode->next;
      }
      leftMost = leftMost->left;
    }
  }
};
