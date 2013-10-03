/*Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  void merge(int A[], int m, int B[], int n)
  {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    int a = m-1;
    int b = n-1;
    while (a>-1 || b>-1)
    {
      if (a==-1)
      {
        A[b]=B[b];
        --b;
        continue;
      }
      else if (b==-1)
      {
        break;
      }
      
      if (A[a]>B[b])
      {
        A[a+b+1]=A[a];
        --a;
      }
      else
      {
        A[a+b+1]=B[b];
        --b;
      }
    }
  }
};

int main(int argc, char** argv)
{
  int A[15]={1,3,5,7,9,11,13,15};
  int B[8] ={2,4,6,8,9};

  Solution s;
  s.merge(A,8,B,5);
  return 0;
}
