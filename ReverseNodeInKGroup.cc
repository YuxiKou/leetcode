/*
  Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
  If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
  You may not alter the values in the nodes, only nodes itself may be changed.
  Only constant memory is allowed.
  For example,
  Given this linked list: 1->2->3->4->5
  For k = 2, you should return: 2->1->4->3->5
  For k = 3, you should return: 3->2->1->4->5
*/
#include <iostream>
#include <stack>

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
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    if(k <= 1 || head == NULL) return head;
    ListNode *prevNode = new ListNode(0);
    ListNode *ret = prevNode;
    prevNode->next = head;
    while(head != NULL)
    {
      ListNode *result = reversePrvt(head, k);
      if(result == NULL) break;
      prevNode->next = result;
      prevNode = head;
      head = head->next;
    }
    return ret->next;
  }
  ListNode *reversePrvt(ListNode *head, int k)
  {
    if(k <= 1 || head == NULL) return head;
    ListNode *last = head->next;
    ListNode *newHead = reversePrvt(head->next, k - 1);
    if(newHead != NULL)
    {
      head->next = last->next;
      last->next = head;
    }
    return newHead;
  }
};
