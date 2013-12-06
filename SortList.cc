/*
  Sort a linked list in O(n log n) time using constant space complexity.
*/
#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
 public:
  ListNode *sortList(ListNode *head)
  {
    if(head == NULL) return NULL;
    ListNode *left = new ListNode(-1);
    ListNode *right = new ListNode(-1);
    ListNode *curNode = head->next;
    ListNode *curEqualLast = head;
    ListNode *curLeft = left;
    ListNode *curRight = right;
    head->next = NULL;
    while(curNode != NULL)
    {
      if(curNode->val == head->val)
      {
        curEqualLast->next = curNode;
        curNode = curNode->next;
        curEqualLast = curEqualLast->next;
        curEqualLast->next = NULL;
      }
      else if(curNode->val < head->val)
      {
        curLeft->next = curNode;
        curNode = curNode->next;
        curLeft = curLeft->next;
        curLeft->next = NULL;
      }
      else
      {
        curRight->next = curNode;
        curNode = curNode->next;
        curRight = curRight->next;
        curRight->next = NULL;
      }
    }
    curLeft = sortList(left->next);
    curRight = sortList(right->next);
    ListNode *leftMax = curLeft;
    while(leftMax != NULL && leftMax->next != NULL) leftMax = leftMax->next;
    if(leftMax != NULL) leftMax->next = head;
    curEqualLast->next = curRight;
    delete left;
    delete right;
    return curLeft == NULL ? head : curLeft;
  }
};
