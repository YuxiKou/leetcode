/*
  Implement pow(x, n).
*/

class Solution
{
 public:
  double pow(double x, int n)
  {
    if(n == 0) return 1;
    if(n == 1) return x;
    double ret = pow(x, n/2);
    if(n % 2 == 0) return ret * ret;
    else return ret * ret * x;
  }
};
