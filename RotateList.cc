/*
  Given a list, rotate the list to the right by k places, where k is non-negative.
  For example:
  Given 1->2->3->4->5->NULL and k = 2,
  return 4->5->1->2->3->NULL.
*/

#include <iostream>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
 public:
  ListNode *rotateRight(ListNode *head, int k)
  {
    if(head == NULL) return NULL;
    if(k == 0) return head;
    ListNode *left = head;
    ListNode *right = head;
    ListNode *ret = NULL;
    for(int i = 0 ; i < k ; ++ i)
    {
      right = right -> next;
      if(right == NULL) right = head;
    }
    if(right == head) return head;
    while(right->next != NULL)
    {
      left = left -> next;
      if(left == NULL) left = head;
      right = right -> next;
    }
    ret = left -> next;
    left -> next = NULL;
    right -> next = head;
    return ret;
  }
};
