/*
  My Submissions
  Follow up for "Remove Duplicates":
  What if duplicates are allowed at most twice?
  For example,
  Given sorted array A = [1,1,1,2,2,3],
  Your function should return length = 5, and A is now [1,1,2,2,3].
*/


class Solution
{
 public:
  int removeDuplicates(int A[], int n)
  {
    if (n < 2) return n;
    int index = 0;
    int m = 0;
    int i = 0;
    while (i < n)
    {
      index = i++;
      while(i < n && A[index] == A[i]) ++i;
      A[m++] = A[index++];
      if(index < i) A[m++] = A[index++];
    }
    return m;
  }
};
