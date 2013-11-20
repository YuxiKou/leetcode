/*
  Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
  You should preserve the original relative order of the nodes in each of the two partitions.
  For example,
  Given 1->4->3->2->5->2 and x = 3,
  return 1->2->2->4->3->5.
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
  ListNode *partition(ListNode *head, int x)
  {
    ListNode *headLeft = new ListNode(0);
    ListNode *headRight = new ListNode(0);
    ListNode *tailLeft = headLeft;
    ListNode *tailRight = headRight;

    while(head != NULL)
    {
      ListNode *curNode = head;
      if(curNode->val < x)
      {
        tailLeft->next = curNode;
        tailLeft = curNode;
      }
      else
      {
        tailRight->next = curNode;
        tailRight = curNode;
      }
      head = head->next;
      curNode->next = NULL;
    }
    tailLeft->next = headRight->next;
    return headLeft->next;
  }
};
