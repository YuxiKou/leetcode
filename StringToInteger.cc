/*
  Implement atoi to convert a string to an integer.

  Hint: Carefully consider all possible input cases. If you want a challenge,
  please do not see below and ask yourself what are the possible input cases.

  Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
  You are responsible to gather all the input requirements up front.

  Requirements for atoi:
  The function first discards as many whitespace characters as necessary until the
  first non-whitespace character is found. Then, starting from this character, takes
  an optional initial plus or minus sign followed by as many numerical digits as possible,
  and interprets them as a numerical value.

  The string can contain additional characters after those that form the integral number,
  which are ignored and have no effect on the behavior of this function.

  If the first sequence of non-whitespace characters in str is not a valid integral number,
  or if no such sequence exists because either str is empty or it contains only
  whitespace characters, no conversion is performed.

  If no valid conversion could be performed, a zero value is returned. If the correct
  value is out of the range of representable values, INT_MAX (2147483647) or
  INT_MIN (-2147483648) is returned.
 */

#include <iostream>
#include <limits>

const int min_int = std::numeric_limits<int>::min();
const int max_int = std::numeric_limits<int>::max();

class Solution {
 public:
  int atoi(const char *str)
  {
    long long ret = 0;
    int i = 0;
    int signSet = 0;
    while( str[i] > 0 )
    {
      std::cout<<"str[i]  ="<<str[i]<<std::endl;
      std::cout<<"signSet ="<<signSet<<std::endl;
      std::cout<<"ret     ="<<ret<<std::endl<<std::endl;
      if ( signSet == 0 )
      {
        if ( str[i] == '-' || str[i] == '+' || str[i] == ' ')
        {
          if (str[i] == '-') signSet = -1;
          else if (str[i] == '+') signSet = 1;
          ++ i;
          continue;
        }
      }
      if (str[i] >= '0' && str[i] <= '9')
      {
        if (signSet == 0 ) signSet = 1;
        ret = ret * 10;
        ret += (str[i] - '0');
        if (signSet * ret > max_int) return max_int;
        else if (signSet * ret < min_int) return min_int;
      }
      else break;
      ++ i;
    }
    return ret * signSet;
  }
};

int main()
{
  Solution s;
  char str[] = "-01324000";
  std::cout<<str<<", "<<s.atoi(str)<<std::endl;
}
