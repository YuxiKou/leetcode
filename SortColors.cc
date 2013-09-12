/*
  Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

  Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

  Note:
  You are not suppose to use the library's sort function for this problem.

  Follow up:
  A rather straight forward solution is a two-pass algorithm using counting sort.
  First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

  Could you come up with an one-pass algorithm using only constant space?
*/

#include <iostream>
#include <string>

class Solution {
 public:
  void sortColors(int A[], int n)
  {
    int i = 0;
    int j = n - 1;
    int cur = 0;
    while( cur <= j )
    {
      switch( A[cur] )
      {
        case 0:
          swap(A, i, cur);
          while(A[i] == 0) ++i;
          if ( cur < i ) cur = i;
          break;
        case 1:
          ++ cur;
          break;
        case 2:
          swap(A, j, cur);
          while(A[j] == 2) --j;
          break;
      }
    }
  }
  void swap(int A[], int i, int j)
  {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  }
};
