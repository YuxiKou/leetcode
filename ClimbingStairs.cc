/*
  You are climbing a stair case. It takes n steps to reach to the top.
  Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution
{
 public:
  int climbStairs(int n)
  {
    if ( n < 2 ) return n;
    int a = 1, b = 1;
    for (int i = 0 ; i < n - 1 ; ++ i )
    {
      a += b;
      int temp = a;
      a = b;
      b = temp;
    }
    return b;
  }
};
