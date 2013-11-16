/*
  Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
  For example:
  Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
   return
   [
   [5,4,11,2],
   [5,8,4,5]
   ]
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
  vector<vector<int> > pathSum(TreeNode *root, int sum)
  {
    vector<vector<int> >ret;
    vector<int> prefix;
    pathSumPrvt(ret, prefix, root, sum);
    return ret;
  }
  void pathSumPrvt(vector<vector<int> > &result, vector<int> prefix, TreeNode *root, int sum)
  {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL)
    {
      if(root->val == sum)
      {
        prefix.push_back(sum);
        result.push_back(prefix);
      }
      return;
    }
    if(root->left != NULL)
    {
      vector<int> temp = prefix;
      temp.push_back(root->val);
      pathSumPrvt(result, temp, root->left, sum - root->val);
    }
    if(root->right != NULL)
    {
      vector<int> temp = prefix;
      temp.push_back(root->val);
      pathSumPrvt(result, temp, root->right, sum - root->val);
    }
  }
};
