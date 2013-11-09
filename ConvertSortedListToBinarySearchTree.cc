/*
  Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
class Solution
{
 public:
  TreeNode *sortedListToBST(ListNode *head)
  {
    if(head == NULL) return NULL;
    int count = 0;
    ListNode * curNode = head;
    while(curNode != NULL)
    {
      curNode = curNode -> next;
      ++count;
    }
    return buildTree(head, 0, count - 1);
  }
  TreeNode *buildTree(ListNode*& node, int start, int end)
  {
    if(start > end) return NULL;
    int mid = ( start + end ) / 2;
    TreeNode *leftChild = buildTree(node, start, mid-1);
    TreeNode *parent = new TreeNode(node->val);
    parent->left = leftChild;
    node = node->next;
    parent->right = buildTree(node, mid+1, end);
    return parent;
  }
};
