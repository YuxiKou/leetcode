/*
  Given a singly linked list L: L0→L1→…→Ln-1→Ln,
  reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

  You must do this in-place without altering the nodes' values.

  For example,
  Given {1,2,3,4}, reorder it to {1,4,2,3}.Given a singly linked list L: L0→L1→…→Ln-1→Ln,
  reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

  You must do this in-place without altering the nodes' values.

  For example,
  Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
  void reorderList(ListNode *head)
  {
    if(head == NULL || head->next == NULL || head->next->next == NULL) return;
    ListNode* ptrSlow = head;
    ListNode* ptrFast = head;
    while(true)
    {
      ptrFast = ptrFast->next;
      if(ptrFast == NULL) break;
      ptrFast = ptrFast->next;
      if(ptrFast == NULL) break;
      ptrSlow = ptrSlow->next;
    }
    ListNode* ptrHead1 = head;
    ListNode* ptrHead2 = reverseList(ptrSlow->next);
    ptrSlow->next = NULL;
    while(ptrHead1 != NULL && ptrHead2 != NULL)
    {
      ListNode* ptrNext1 = ptrHead1->next;
      ListNode* ptrNext2 = ptrHead2->next;
      ptrHead1->next = ptrHead2;
      ptrHead2->next = ptrNext1;
      ptrHead1 = ptrNext1;
      ptrHead2 = ptrNext2;
    }
  }
  ListNode* reverseList(ListNode *head)
  {
    if(head == NULL || head->next == NULL) return head;
    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
  }
};

void print(ListNode* head)
{
  while(head != NULL)
  {
    std::cout<<head->val<<std::endl;
    head = head->next;
  }
  std::cout<<std::endl;
}

int main()
{
  Solution sol;
  ListNode* head = new ListNode(0);
  ListNode* end = head;
  for(int i = 1 ; i < 10 ; ++ i)
  {
    ListNode* newNode = new ListNode(i);
    end->next = newNode;
    end = newNode;
  }
  std::cout<<"before"<<std::endl;
  print(head);
  sol.reorderList(head);
  std::cout<<"after"<<std::endl;
  print(head);
  return 0;
}
