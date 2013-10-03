/*
  Implement int sqrt(int x).
  Compute and return the square root of x.
*/

class Solution
{
 public:
  int sqrt(int x)
  {
    if (x < 2) return x;
    int ret = x / 2;
    while(!(ret * ret <= x && (ret + 1) * (ret + 1) > x)) ret = (ret + x / ret) / 2;
    return ret;
  }
};
