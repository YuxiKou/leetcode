/*
  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

  P   A   H   N
  A P L S I I G
  Y   I   R
  And then read line by line: "PAHNAPLSIIGYIR"
  Write the code that will take a string and make this conversion given a number of rows:

  string convert(string text, int nRows);
  convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <iostream>
#include <string>

class Solution
{
 public:
  std::string convert(std::string s, int nRows)
  {
    if (nRows < 2) return s;
    int length = s.length();
    if (length <= nRows ) return s;

    int m = ( nRows - 1 ) * 2;
    int nGroups = length / m;
    int nLeft = length % m;
    int *Rows = new int[nRows];
    int nthGroup, nthRow, index, mod, mul;

    Rows[0] = 0;
    Rows[1] = nGroups + ( nLeft > 0 );
    for ( int i = 2 ; i < nRows ; ++ i )
    {
      Rows[i] = Rows[i-1] + nGroups * 2 + ( nLeft > i - 1 ) + ( nLeft > m - i + 1);
    }

    std::string ret(length,' ');
    for( int i = 0 ; i < length ; ++ i )
    {
      nthGroup = i / m;
      nthRow = mod = i % m;
      if (nthRow >= nRows) nthRow = m - nthRow;
      if (nthRow == 0 || nthRow == nRows - 1 ) mul = 1;
      else mul = 2;
      index = Rows[nthRow] + mul * nthGroup;
      if (nthRow != 0 && nthRow != nRows - 1 && mod >= m - nthRow) ++ index;
      ret[index] = s[i];
    }
    return ret;
  }
};

int main()
{
  std::string s = "abcde";
  int nRow = 4;
  Solution sol;
  std::cout<<sol.convert(s,nRow)<<std::endl;
}
