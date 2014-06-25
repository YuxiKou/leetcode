/*
  A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
  Return a deep copy of the list.
*/
#include <iostream>

using namespace std;

struct RandomListNode
{
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution
{
 public:
  RandomListNode *copyRandomList(RandomListNode *head)
  {
    if(head == NULL) return NULL;
    RandomListNode *curNode = head;
    while(curNode != NULL)
    {
      RandomListNode *nextNode = curNode->next;
      curNode->next = new RandomListNode(curNode->label);
      curNode->next->next = nextNode;
      curNode = nextNode;
    }
    curNode = head;
    while(curNode != NULL)
    {
      if(curNode->random)
      {
        curNode->next->random = curNode->random->next;
      }
      curNode = curNode->next->next;
    }
    curNode = head;
    RandomListNode *newHead = head->next;
    RandomListNode *newCurNode;
    while(curNode != NULL)
    {
      newCurNode = curNode->next;
      curNode->next = newCurNode->next;
      curNode = curNode->next;
      if(curNode != NULL) newCurNode->next = curNode->next;
      else newCurNode->next = NULL;
    }
    return newHead;
  }
};
