/*
  Given a linked list, swap every two adjacent nodes and return its head.
  For example,
  Given 1->2->3->4, you should return the list as 2->1->4->3.
  Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
  ListNode *swapPairs(ListNode *head)
  {
    if(head == NULL || head->next == NULL) return head;

    ListNode *temp1 = new ListNode(0);
    ListNode *temp2;
    temp1->next = head;
    head = temp1;
    while (temp1->next != NULL && temp1->next->next != NULL)
    {
      temp2 = temp1->next;
      temp1->next = temp2->next;
      temp2->next = temp2->next->next;
      temp1->next->next = temp2;
      temp1 = temp2;
    }
    return head->next;
  }
};
int main()
{
  return 0;
}
