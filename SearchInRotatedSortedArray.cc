/*
  Suppose a sorted array is rotated at some pivot unknown to you beforehand.
  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
  You are given a target value to search. If found in the array return its index, otherwise return -1.
  You may assume no duplicate exists in the array.
*/
#include <iostream>
#include <string>

class Solution
{
 public:
  int search(int A[], int n, int target)
  {
    if (n == 0) return -1;
    return searchPrvt(A, 0, n - 1, target);
  }
  int searchPrvt(int A[], int start, int end, int target)
  {
    if ( start > end ) return -1;
    int mid = ( start + end ) / 2;
    if ( A[mid] == target ) return mid;
    if ( A[mid] >= A[start] )
    {
      if ( A[mid] > target && target >= A[start] ) return searchPrvt(A, start, mid - 1, target);
      else return searchPrvt(A, mid + 1, end, target);
    }
    else
    {
      if ( A[mid] < target && target <= A[end]) return searchPrvt(A, mid + 1, end, target);
      else return searchPrvt(A, start, mid - 1, target);
    }
  }
};

int main()
{
  Solution sol;
  int ary[] = {1,3};
  int target = 0;
  std::cout<<sol.search(ary, sizeof(ary) / sizeof(int), target);
  return 0;
}
