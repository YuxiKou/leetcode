/*
  Given an array of non-negative integers, you are initially positioned at the first index of the array.
  Each element in the array represents your maximum jump length at that position.
  Your goal is to reach the last index in the minimum number of jumps.
  For example:
  Given array A = [2,3,1,1,4]
  The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/
#include <algorithm>

using namespace std;

class Solution
{
 public:
  int jump(int A[], int n)
  {
    if ( n <= 0 ) return true;

    int* jumpAry = new int[n]();
    jumpAry[0] = A[0];
    if(A[0] > n - 1) return 1;
    for (int i = 1 ; i < n ; ++ i )
    {
      if (jumpAry[i-1] == 0 ) return -1;
      if ( A[i] + i >= n - 1) return i+1;
      jumpAry[i] = max(jumpAry[i-1] - 1, A[i]);
    }
    return 0;
  }
};
