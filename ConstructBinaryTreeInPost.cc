/*
  Given inorder and postorder traversal of a tree, construct the binary tree.
  You may assume that duplicates do not exist in the tree.
*/
#include <vector>

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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    return buildTreePrvt(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
  }
  TreeNode *buildTreePrvt(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd)
  {
    if(inStart > inEnd || postStart > postEnd) return NULL;
    TreeNode *root = new TreeNode(postorder[postEnd]);
    int inIndex = -1;
    for(int i = inStart; i <= inEnd; ++i)
    {
      if(inorder[i] == postorder[postEnd])
      {
        inIndex = i;
        break;
      }
    }
    int length = inIndex - inStart;
    root->left = buildTreePrvt(inorder, inStart, inIndex - 1, postorder, postStart, postStart + length - 1);
    root->right = buildTreePrvt(inorder, inIndex + 1, inEnd, postorder, postStart + length, postEnd - 1);
    return root;
  }
};

