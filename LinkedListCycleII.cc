/*
  Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
  Follow up:
  Can you solve it without using extra space?
*/

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
 public:
  ListNode *detectCycle(ListNode *head)
  {
    ListNode *first = head;
    ListNode *second = head;
    while(first != NULL && second != NULL)
    {
      second = second -> next;
      if(second == NULL) return NULL;
      second = second -> next;
      if(second == NULL) return NULL;
      first = first -> next;
      if(first == second) break;
    }
    second = head;
    while(first != second)
    {
      first = first -> next;
      second = second -> next;
    }
    return first;
  }
};
