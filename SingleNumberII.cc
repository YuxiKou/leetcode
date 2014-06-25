/*
  Given an array of integers, every element appears three times except for one. Find that single one.
*/
#include <iostream>
using namespace std;

class Solution
{
 public:
  int singleNumber(int A[], int n)
  {
    int one = 0, two = 0, three = 0;
    for(int i = 0 ; i < n ; ++ i)
    {
      two |= one & A[i];
      one ^= A[i];
      three = one & two;
      one &= ~three;
      two &= ~three;
    }
    return one;
  }
};

int main()
{
  int A[] = {1,1,1,1,1,1,2,2};
  Solution sol;
  cout<<sol.singleNumber(A,sizeof(A) / sizeof(int))<<endl;
  return 0;
}
