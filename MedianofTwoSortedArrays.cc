/*There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n)
  {
    int total = m + n;
    if(total%2==1) return fms(A,m,B,n,total/2+1);
    else return (fms(A,m,B,n,total/2)+fms(A,m,B,n,total/2+1))/2;
  }
  double fms(int A[], int m, int B[], int n, int k)
  {
    if (m>n) return fms(B,n,A,m,k);
    if (m==0) return B[k-1];
    if (k==1) return min(A[0],B[0]);

    int pa = min(k/2,m);
    int pb = k-pa;
    if (A[pa-1]<=B[pb-1]) return fms(A+pa,m-pa,B,n,k-pa);
    else return fms(A,m,B+pb,n-pb,k-pb);
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
