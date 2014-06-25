/*
  Sort a linked list using insertion sort.
*/

#include <iostream>

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
  ListNode *insertionSortList(ListNode *head)
  {
    if(head == NULL) return NULL;
    ListNode *newHead = new ListNode(0);
    newHead->next = head;
    ListNode *curNode = head->next;
    head->next = NULL;
    while(curNode != NULL)
    {
      ListNode *preNode = newHead;
      while(preNode->next != NULL && preNode->next->val < curNode->val)
      {
        preNode = preNode->next;
      }
      ListNode *nextNode = curNode->next;
      curNode->next = preNode->next;
      preNode->next = curNode;
      curNode = nextNode;
    }
    return newHead->next;
  }
};
