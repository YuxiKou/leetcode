/*
  Given two binary strings, return their sum (also a binary string).

  For example,
  a = "11"
  b = "1"
  Return "100".

*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
 public:
  string addBinary(string a, string b)
  {
    string ret;
    int lengthA = a.length();
    int lengthB = b.length();
    if (lengthA == 0 ) return b;
    if (lengthB == 0 ) return a;
    int carry = 0, num = 0;
    while (lengthA > 0 || lengthB > 0 || carry > 0)
    {
      --lengthA;
      --lengthB;
      num = carry;
      if (lengthA >= 0) num += a[lengthA] - '0';
      if (lengthB >= 0) num += b[lengthB] - '0';
      carry = num / 2;
      num %= 2;
      char temp = num + '0';
      ret = temp + ret;
    }
    return ret;
  }
};

int main()
{
  Solution sol;
  cout<<sol.addBinary("111111","1")<<endl;
  return 0;
}
