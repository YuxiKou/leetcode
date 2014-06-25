/*
  Given an array and a value, remove all instances of that value in place and return the new length.
  The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution
{
 public:
  int removeElement(int A[], int n, int elem)
  {
    if ( n == 0 ) return 0;
    int length = n;
    int index1 = 0, index2 = n - 1;
    while(true)
    {
      while(index1< index2 && A[index1] != elem) ++index1;
      while(index1<= index2 && A[index2] == elem)
      {
        --index2;
        --length;
      }
      if(index1 >= index2 ) break;
      int temp = A[index1];
      A[index1] = A[index2];
      A[index2] = temp;
    }
    return length;
  }
};
