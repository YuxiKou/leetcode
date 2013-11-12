/*
  Implement pow(x, n).
*/

#include <iostream>

using namespace std;

class Solution
{
 public:
  double pow(double x, int n)
  {
    if(n == 0) return 1;
    if(n == 1) return x;
    double ret = n < 0 ? pow(x, -n/2) : pow(x, n/2);
    if(n % 2 == 0) ret *= ret;
    else ret *= ret * x;
    if(n < 0) return 1.0/ret;
    else return ret;
  }
};
int main()
{
  Solution sol;
  sol.pow(1.00000, -2147483648);
  return 0;
}
