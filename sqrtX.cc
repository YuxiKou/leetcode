/*
  Implement int sqrt(int x).
  Compute and return the square root of x.
*/
#include <limits>
#include <algorithm>
#include <cmath>

class Solution
{
 public:
  int sqrt(int x)
  {
    if(x <= 0) return 0;
    const int SQRT_INT_MAX = std::sqrt(std::numeric_limits<int>::max());
    int start = 0;
    int end = (x >> 1) < SQRT_INT_MAX ? (x >> 1) + 1: SQRT_INT_MAX;
    while(start < end)
    {
      int mid = (start + end) >> 1;
      int sq = mid * mid;
      if((sq == x) || (sq < x && (sq + (mid << 1) + 1 )> x)) return mid;
      if(sq < x) start = mid + 1;
      else end = mid - 1;
    }
    return (start + end)>>1;
  }
};
