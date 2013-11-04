/*
  Follow up for "Search in Rotated Sorted Array":
  What if duplicates are allowed?

  Would this affect the run-time complexity? How and why?

  Write a function to determine if a given target is in the array.
*/
class Solution
{
 public:
  bool search(int A[], int n, int target)
  {
    if (n == 0) return -1;
    return searchPrvt(A, 0, n - 1, target);
  }
  boll searchPrvt(int A[], int start, int end, int target)
  {
    if ( start > end ) return false;
    int mid = ( start + end ) / 2;
    if ( A[mid] == target ) return true;
    if ( A[mid] > A[start] )
    {
      if ( A[mid] > target && target >= A[start] ) return searchPrvt(A, start, mid - 1, target);
      else return searchPrvt(A, mid + 1, end, target);
    }
    else if( A[mid] < A[start])
    {
      if ( A[mid] < target && target <= A[end]) return searchPrvt(A, mid + 1, end, target);
      else return searchPrvt(A, start, mid - 1, target);
    }
    else
    {
      return searchPrvt(A, start + 1, end, target);
    }
  }
};
