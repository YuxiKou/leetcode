/*
  Given a number represented as an array of digits, plus one to the number.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int> &digits)
  {
    bool allNine = true;
    int length = digits.size();
    if (length == 0) return digits;
    for( int i = 0 ; i < length ; ++ i)
    {
      if (digits[i] != 9 )
      {
        allNine = false;
        break;
      }
    }
    if (allNine)
    {
      vector<int> ret(length+1, 0);
      ret[0] = 1;
      return ret;
    }
    else
    {
      int carry = 0;
      ++digits[length-1];
      for( int i = length - 1 ; i > 0 ; -- i)
      {
        if (digits[i] == 10)
        {
          carry = 1;
          digits[i] = 0;
          ++digits[i-1];
        }
        else
        {
          carry = 0;
        }
      }
    }
    return digits;
  }
};
