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
        vector<ListNode *>::iterator it = lists.begin();
        while (it != lists.end())
        {
            if (*it == NULL) lists.erase(it);
            else ++it;
        }
        if (lists.size() < 1) return NULL;

        ListNode *head = NULL, *cur = NULL;
        make_heap(lists.begin(), lists.end(), comp());

        while (lists.size() > 0)
        {
            if (head == NULL) head = cur = lists[0];
            else cur = cur->next = lists[0];

            pop_heap(lists.begin(), lists.end(), comp());
            int last = lists.size() - 1;
            if (lists[last]->next != NULL)
            {
                lists[last] = lists[last]->next;
                push_heap(lists.begin(), lists.end(), comp());
            }
            else lists.pop_back();
        }

        return head;
    }
    class comp
    {
    public:
        bool operator() (const ListNode *l, const ListNode *r) const
        {
            return (l->val > r->val);
        }
    };
};
