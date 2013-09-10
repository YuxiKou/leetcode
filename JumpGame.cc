/*
  Given an array of non-negative integers, you are initially positioned at the first index of the array.

  Each element in the array represents your maximum jump length at that position.

  Determine if you are able to reach the last index.

  For example:
  A = [2,3,1,1,4], return true.

  A = [3,2,1,0,4], return false.
*/
#include <iostream>
#include <string>
#include <algorithm>

class Solution {
 public:
  bool canJump(int A[], int n)
  {
    if ( n <= 0 ) return true;

    int* jumpAry = new int[n]();
    jumpAry[0] = A[0];
    for (int i = 1 ; i < n ; ++ i )
    {
      if (jumpAry[i-1] == 0 ) return false;
      if ( A[i] + i >= n - 1) return true;
      jumpAry[i] = std::max(jumpAry[i-1] - 1, A[i]);
    }
    return true;
  }
};

int main()
{
  Solution sol;
  int input[] = {1,0,2};
  std::cout<<sol.canJump(input,sizeof(input) / sizeof(int))<<std::endl;
  return 0;
}
