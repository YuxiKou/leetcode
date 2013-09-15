/*
  Given a sorted linked list, delete all duplicates such that each element appear only once.
  For example,
  Given 1->1->2, return 1->2.
  Given 1->1->2->3->3, return 1->2->3.
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
#include <algorithm>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
 public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    if (head == NULL ) return NULL;
    ListNode *temp = head;
    ListNode *temp1;
    while(temp->next != NULL)
    {
      if (temp->val == temp->next->val)
      {
        temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
      }
      else
      {
        temp = temp->next;
      }
    }
    return head;
  }
};
