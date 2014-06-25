/*
  Given an unsorted integer array, find the first missing positive integer.
  For example,
  Given [1,2,0] return 3,
  and [3,4,-1,1] return 2.
  Your algorithm should run in O(n) time and uses constant space.
*/
#include <iostream>

using namespace std;

class Solution
{
 public:
  int firstMissingPositive(int A[], int n)
  {
    if(n == 0) return 1;

    for (int i = 0; i < n; ++i)
    {
      while(A[i] != i + 1)
      {
        if(A[i] < 1 || A[i] > n || A[A[i] - 1] == A[i]) break;
        int temp = A[i];
        A[i] = A[temp - 1];
        A[temp - 1] = temp;
      }
    }
    for (int i = 0; i < n; ++i)
    {
      if(A[i] != i + 1) return i + 1;
    }
    return n + 1;
  }
};
int main()
{
  int A[] = {1};
  Solution sol;
  sol.firstMissingPositive(A, sizeof(A) / sizeof(int));
  return 0;
}
