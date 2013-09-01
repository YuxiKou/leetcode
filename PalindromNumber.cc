/*
  Determine whether an integer is a palindrome. Do this without extra space.

  Some hints:
  Could negative integers be palindromes? (ie, -1)

  If you are thinking of converting the integer to string, note the
  restriction of using extra space.

  You could also try reversing an integer. However, if you have solved the
  problem "Reverse Integer", you know that the reversed integer might
  overflow. How would you handle such case?

  There is a more generic way of solving this problem.
*/

#include <iostream>
#include <limits>

const int max_int = std::numeric_limits<int>::max();
const int min_int = std::numeric_limits<int>::min();

class Solution {
 public:
  bool isPalindrome(int x)
  {
    if ( x < 0 ) return false;
    if ( x < 10 ) return true;
    return PrvtIsPal(x,x);
  }
  bool PrvtIsPal(int x, int &y)
  {
    if ( x < 0 ) return false;
    if ( x == 0 ) return true;
    if (PrvtIsPal( x / 10, y ) && ( x % 10 == y % 10) )
    {
      y /= 10;
      return true;
    }
    return false;
  }
};
int main(int argc, char* argv[])
{
  Solution s;
  int val;
  //  std::cin>>val;
  val = 123456654321;
  std::cout<<val<<", "<<s.isPalindrome(val)<<std::endl;
}
