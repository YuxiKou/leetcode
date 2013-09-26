/*
  Given numRows, generate the first numRows of Pascal's triangle.
  For example, given numRows = 5,
  Return

  [
  [1],
  [1,1],
  [1,2,1],
  [1,3,3,1],
  [1,4,6,4,1]
  ]
*/

#include <iostream>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int> > generate(int numRows)
  {
    std::vector<std::vector<int> > ret;
    if (numRows > 0 ) ret.push_back(std::vector<int>(1,1));
    for( int i = 1 ; i < numRows; ++ i)
    {
      std::vector<int> oneRow(i+1,0);
      oneRow[0] = 1;
      for( int j = 1 ; j < i ; ++ j)
      {
        oneRow[j] = ret[i-1][j-1] + ret[i-1][j];
      }
      oneRow[i] = 1;
      ret.push_back(oneRow);
    }
    return ret;
  }
};
