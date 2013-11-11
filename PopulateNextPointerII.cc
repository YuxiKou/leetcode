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

  Follow up for problem "Populating Next Right Pointers in Each Node".

  What if the given tree could be any binary tree? Would your previous solution still work?
  Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
  After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
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
    TreeLinkNode *curNode = root;
    while(curNode != NULL)
    {
      TreeLinkNode *prevNode = NULL;
      TreeLinkNode *nextLevel = NULL;
      while(curNode != NULL)
      {
        if(nextLevel == NULL) nextLevel = (curNode->left != NULL) ? curNode->left : curNode->right;
        if(curNode->left != NULL)
        {
          if(prevNode != NULL) prevNode->next = curNode->left;
          prevNode = curNode->left;
        }
        if(curNode->right != NULL)
        {
          if(prevNode != NULL) prevNode->next = curNode->right;
          prevNode = curNode->right;
        }
        curNode = curNode->next;
      }
      curNode = nextLevel;
    }
  }
};
