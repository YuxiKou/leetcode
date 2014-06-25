/*
  Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

  If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

  The replacement must be in-place, do not allocate extra memory.

  Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
  1,2,3 → 1,3,2
  3,2,1 → 1,2,3
  1,1,5 → 1,5,1
*/
#include <vector>

using namespace std;

class Solution
{
 public:
  void nextPermutation(vector<int> &num)
  {
    if(num.size() < 2) return;
    int permuteIndex = -1;
    int changeIndex = -1;
    int n = num.size();
    for(int i = n - 1; i > 0; --i)
    {
      if(num[i-1] < num[i])
      {
        permuteIndex = i - 1;
        break;
      }
    }
    if(permuteIndex == -1)
    {
      sort(num.begin(), num.end());
      return;
    }
    for(int i = n - 1; i > 0; --i)
    {
      if(num[i] > num[permuteIndex])
      {
        changeIndex = i;
        break;
      }
    }
    swap(num[permuteIndex], num[changeIndex]);
    sort(num.begin() + permuteIndex + 1, num.end());
  }
};
