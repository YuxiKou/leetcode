/*
  Given a linked list, remove the nth node from the end of list and return its head.

  For example,

  Given linked list: 1->2->3->4->5, and n = 2.

  After removing the second node from the end, the linked list becomes 1->2->3->5.
  Note:
  Given n will always be valid.
  Try to do this in one pass.
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
#include <string>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode* nthNode = head;
    ListNode* lastNode = head;
    for( int i = 0 ; i < n ; ++ i)
    {
      if (lastNode == NULL) return head;
      lastNode = lastNode -> next;
    }
    if (lastNode == NULL)
    {
      nthNode = head -> next;
      delete head;
      return nthNode;
    }
    while (lastNode -> next != NULL)
    {
      nthNode = nthNode -> next;
      lastNode = lastNode -> next;
    }
    lastNode = nthNode -> next;
    nthNode -> next = nthNode -> next -> next;
    delete lastNode;
    return head;
  }
};
