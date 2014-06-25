/*
  Given a roman numeral, convert it to an integer.
  Input is guaranteed to be within the range from 1 to 3999.
 */

#include <iostream>
#include <string>
#include <map>

class Solution {
public:
  int romanToInt(std::string s)
  {
    std::map<char,int> romanMap;
    initMap(romanMap);
    int ret = 0;
    int length = s.length();
    for ( int i = 0 ; i < length ; ++ i )
    {
      if ( i < length - 1 && romanMap[s[i]] < romanMap[s[i+1]] )
      {
        ret += romanMap[s[i+1]] - romanMap[s[i]];
        ++i;
      }
      else
      {
        ret += romanMap[s[i]];
      }
    }
    return ret;
  }
  void initMap(std::map<char,int> &romanMap)
  {
    romanMap['M'] = 1000;
    romanMap['D'] = 500;
    romanMap['C'] = 100;
    romanMap['L'] = 50;
    romanMap['X'] = 10;
    romanMap['V'] = 5;
    romanMap['I'] = 1;
  }
};

int main()
{
  Solution sol;
  std::string input;
  std::cin>>input;
  std::cout<<input<<": "<<sol.romanToInt(input)<<std::endl;
}
