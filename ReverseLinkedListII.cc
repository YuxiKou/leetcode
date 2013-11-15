/*
  Reverse a linked list from position m to n. Do it in-place and in one-pass.
  For example:
  Given 1->2->3->4->5->NULL, m = 2 and n = 4,
  return 1->4->3->2->5->NULL.
  Note:
  Given m, n satisfy the following condition:
  1 ≤ m ≤ n ≤ length of list.
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
  ListNode *reverseBetween(ListNode *head, int m, int n)
  {
    ListNode *newHead = new ListNode(0);
    newHead->next = head;
    ListNode *prevNode = newHead;
    for(int i = 0 ; i < m - 1; ++ i)
    {
      prevNode = prevNode->next;
    }
    prevNode->next = reversePrvt(prevNode->next, n - m + 1);
    return newHead->next;
  }
  ListNode *reversePrvt(ListNode *head, int m)
  {
    if(m <= 1 || head == NULL) return head;
    ListNode *last = head->next;
    ListNode *newHead = reversePrvt(head->next, m - 1);
    head->next = last->next;
    last->next = head;
    return newHead;
  }
};
