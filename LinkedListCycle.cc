/*
  Given a linked list, determine if it has a cycle in it.
  Follow up:
  Can you solve it without using extra space?
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
  bool hasCycle(ListNode *head)
  {
    if(head == NULL) return false;
    ListNode *first = head;
    ListNode *second = head;
    while(first != NULL && second != NULL)
    {
      second = second -> next;
      if(second == NULL) return false;
      second = second -> next;
      if(second == NULL) return false;
      first = first -> next;
      if(first == second) return true;
    }
    return false;
  }
};
