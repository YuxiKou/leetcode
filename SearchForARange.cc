/*
  Given a sorted array of integers, find the starting and ending position of a given target value.
  Your algorithm's runtime complexity must be in the order of O(log n).
  If the target is not found in the array, return [-1, -1].
  For example,
  Given [5, 7, 7, 8, 8, 10] and target value 8,
  return [3, 4].
*/
#include <iostream>
#include <vector>

class Solution {
 public:
  std::vector<int> searchRange(int A[], int n, int target)
  {
    int start = -1, end = -1;
    for( int i = 0 ; i < n ; ++ i )
    {
      if (A[i] == target)
      {
        if(start == -1) start = i;
        end = i;
      }
      else if (start > -1) break;
    }
    std::vector<int> ret;
    ret.push_back(start);
    ret.push_back(end);
    return ret;
  }
};
