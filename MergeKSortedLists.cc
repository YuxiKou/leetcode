/*
  Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
#include <vector>

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
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    if(lists.size() == 0) return NULL;
    ListNode *head = lists[0];
    for(vector<ListNode*>::size_type i = 1; i < lists.size(); ++ i)
    {
      head = mergeTwoLists(head, lists[i]);
    }
    return head;
  }
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode *head = NULL;
    ListNode *ind  = NULL;

    if( l1 == NULL ) return l2;
    if( l2 == NULL ) return l1;

    while(l1 != NULL || l2 != NULL)
    {
      if( l1 == NULL )
      {
        ind->next = l2;
        break;
      }
      if( l2 == NULL )
      {
        ind->next = l1;
        break;
      }
      if (l1->val < l2->val)
      {
        if (head == NULL)
        {
          head = l1;
          ind = head;
        }
        else
        {
          ind->next = l1;
          ind = l1;
        }
        l1 = l1->next;
      }
      else
      {
        if (head == NULL)
        {
          head = l2;
          ind = head;
        }
        else
        {
          ind->next = l2;
          ind = l2;
        }
        l2 = l2->next;
      }
    }
    return head;
  }
};
