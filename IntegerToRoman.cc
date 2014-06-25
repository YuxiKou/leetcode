/*
  Given an integer, convert it to a roman numeral.
  Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
#include <string>

class Solution {
 public:
  std::string intToRoman(int num)
  {
    std::string ret;
    ret += convertToRoman(num, 1000, "  M");
    ret += convertToRoman(num, 100, "MDC");
    ret += convertToRoman(num, 10, "CLX");
    ret += convertToRoman(num, 1, "XVI");
    return ret;
  }
  std::string convertToRoman(int &num, int thresh, const char* letter)
  {
    std::string ret;
    int digit;
    digit = num / thresh;
    if ( digit == 9 )
    {
      ret += letter[2];
      ret += letter[0];
      digit = 0;
    }
    if ( digit == 4 )
    {
      ret += letter[2];
      ret += letter[1];
      digit = 0;
    }
    if ( digit >= 5)
    {
      ret += letter[1];
      digit -= 5;
    }
    while ( -- digit >= 0 )
    {
      ret += letter[2];
    }
    num %= thresh;
    return ret;
  }
};


int main()
{
  Solution sol;
  int input ;
  std::cin>>input;
  std::cout<<input<<": "<<sol.intToRoman(input)<<std::endl;
}
