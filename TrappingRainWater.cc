/*
  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
  For example,
  Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
class Solution
{
 public:
  int trap(int A[], int n)
  {
    if(n < 3) return 0;
    int leftMax = 0;
    int rightMax = 0;
    int left = 0;
    int right = n - 1;
    int volumn = 0;
    while(left < right)
    {
      if(A[left] > leftMax) leftMax = A[left];
      if(A[right] > rightMax) rightMax = A[right];
      if(leftMax < rightMax)
      {
        volumn += leftMax - A[left];
        left++;
      }
      else
      {
        volumn += rightMax - A[right];
        right--;
      }
    }
    return volumn;
  }
};
int main()
{
  return 0;
}
