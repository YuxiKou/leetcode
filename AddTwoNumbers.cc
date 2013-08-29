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

    head = new ListNode(0,NULL);
    tempPtr = head;

    while(tempPtr1->next != NULL || tempPtr2->next != NULL || carry > 0 )
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

      tempPtr->next = new ListNode(val,NULL);
      tempPtr = tempPtr->next;

      tempPtr1 = tempPtr1->next;
      tempPtr2 = tempPtr2->next;
    }
    return head->next;
  }
};
