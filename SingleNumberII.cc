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
      three = two & A[i];
      two = (two & ~ A[i]) | (one & A[i]);
      one = (one ^ A[i]) & ~two;
      cout<<"A[i] = "<<A[i]<<", one = " <<one<<", two = "<<two<<", three = "<<three<<endl;
    }
    return two;
  }
};

int main()
{
  int A[] = {1,1,1,1,1,1,2,2};
  Solution sol;
  cout<<sol.singleNumber(A,sizeof(A) / sizeof(int))<<endl;
  return 0;
}
