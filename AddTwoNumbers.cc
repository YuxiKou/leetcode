/**
   You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

   Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
   Output: 7 -> 0 -> 8

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

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    if (l1 == NULL && l2 == NULL ) return 0;
    if (l1 == NULL ) return l2;
    if (l2 == NULL ) return l1;

    ListNode* tempPtr1 = l1;
    ListNode* tempPtr2 = l2;
    ListNode* head = NULL;
    ListNode* tempPtr = NULL;

    int carry = 0;
    int val = 0;

    head = new ListNode(0);
    tempPtr = head;

    while(tempPtr1 != NULL || tempPtr2 != NULL || carry > 0 )
    {
      val = carry;
      if (tempPtr1 != NULL) val += tempPtr1->val;
      if (tempPtr2 != NULL) val += tempPtr2->val;

      if (val > 9)
      {
        val -= 10;
        carry = 1;
      }
      else
      {
        carry = 0;
      }

      tempPtr->next = new ListNode(val);
      tempPtr = tempPtr->next;

      if (tempPtr1 != NULL) tempPtr1 = tempPtr1->next;
      if (tempPtr2 != NULL) tempPtr2 = tempPtr2->next;
    }
    return head->next;
  }
};

int print(ListNode * list)
{
  while(list != NULL )
  {
    std::cout<<list->val<<", ";
    list = list->next;
  }
  std::cout<<std::endl;
  return 0;
}

int main(int argc, char** argv)
{
  Solution s;
  ListNode* l1 = new ListNode(1);
  ListNode* l2 = new ListNode(2);
  ListNode* temp1 = l1;
  ListNode* temp2 = l2;
  for (int i = 0 ; i < 4 ; ++ i )
  {
    temp1->next = new ListNode(i*2);
    temp1 = temp1->next;

    temp2->next = new ListNode(i+5);
    temp2 = temp2->next;
  }
  temp2->next = new ListNode(9);
  temp2 = temp2->next;
  std::cout<<"L1:"<<std::endl;
  print(l1);
  std::cout<<"L2:"<<std::endl;
  print(l2);
  std::cout<<"sum:"<<std::endl;
  print(s.addTwoNumbers(l1,l2));
}
