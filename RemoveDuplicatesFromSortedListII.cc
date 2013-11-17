/*
  Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
  For example,
  Given 1->2->3->3->4->4->5, return 1->2->5.
  Given 1->1->1->2->3, return 2->3.
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
  ListNode *deleteDuplicates(ListNode *head)
  {
    if(head == NULL) return NULL;
    ListNode *newHead = new ListNode(0);
    newHead->next = head;
    ListNode *prevNode = newHead;
    ListNode *curNode = head;
    while(curNode != NULL && curNode->next != NULL)
    {
      if(curNode->val == curNode->next->val)
      {
        curNode = remove(curNode);
        prevNode->next = curNode;
      }
      else
      {
        prevNode = curNode;
        curNode = curNode->next;
      }
    }
    return newHead->next;
  }
  ListNode *remove(ListNode *head)
  {
    if(head == NULL) return NULL;
    int val = head->val;
    ListNode *temp;
    while(head != NULL && head->val == val)
    {
      temp = head;
      head = head->next;
      delete temp;
    }
    return head;
  }
};

void printList(ListNode *head)
{
  while(head != NULL)
  {
    cout<<head->val<<endl;
    head = head->next;
  }
  cout<<endl;
}
int main()
{
  Solution sol;
  ListNode *head = new ListNode(1);
  ListNode *second = new ListNode(1);
  head->next = second;
  printList(head);
  sol.deleteDuplicates(head);
  printList(head);
  return 0;
}
