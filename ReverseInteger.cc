/*
  Reverse digits of an integer.

  Example1: x = 123, return 321
  Example2: x = -123, return -321

  Have you thought about this?
  Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

  If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

  Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

  Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).
*/
#include <iostream>
#include <limits>

const int min_int = std::numeric_limits<int>::min();
const int max_int = std::numeric_limits<int>::max();

class Solution
{
 public:
  int reverse(int x)
  {
    int ret = 0;
    int isNegative = x < 0 ? -1 : 1;

    x *= isNegative;
    while(x > 0)
    {
      ret = ret * 10 + x % 10;
      x /= 10;
    }
    if (ret < 0) return -1;
    return isNegative * ret;
  }
};

int main()
{
  Solution s;
  int val;
  std::cin>>val;
  std::cout<<val<<", "<<s.reverse(val)<<std::endl;
}
