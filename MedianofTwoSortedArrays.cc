/*There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n)
  {
    int curIndexInA = m / 2;
    int curIndexInB;
    int left = 0,right = m-1;
    while(left < right)
    {
      curIndexInB = ( m + n ) / 2 - curIndexInA;
      if (curIndexInB >= 0 && curIndexInB < n )
      {
        if (B[curIndexInB] > A[curIndexInA])
        {
          left = left + (right - left) / 2 ;
          curIndexInA = (right + left) / 2 ;
        }
        else if (B[curIndexInB+1] < A[curIndexInA])
        {
          right = right - (right - left) / 2;
          curIndexInA = (right + left) / 2;
        }
        else
        {
          return A[curIndexInA];
        }
      }
    }
    return -1;
  }
};


int main(int argc, char **argv)
{
  int A[] = {1,3,5,7,9,11,13};
  int B[] = {2,4,12,14,15,16,17};
  Solution mySolution;
  cout<<mySolution.findMedianSortedArrays(A,sizeof(A)/sizeof(int), B,sizeof(B)/sizeof(int))<<endl;
  return 0;
}
