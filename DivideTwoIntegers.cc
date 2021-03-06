/*
  Divide two integers without using multiplication, division and mod operator.
*/
class Solution
{
 public:
  int divide(int dividend, int divisor)
  {
    long long ret = 0;
    long long dd = dividend;
    if(dd < 0) dd = -dd;
    long long dr = divisor;
    if(dr < 0) dr = -dr;

    while(dd >= dr)
    {
      long long val = dr;
      for(int i = 0; val <= dd; ++ i)
      {
        dd -= val;
        ret += 1 << i;
        val <<= 1;
      }
    }
    return (dividend^divisor)>>31 ? -ret : ret;
  }
};
