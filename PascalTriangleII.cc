/*
  Given an index k, return the kth row of the Pascal's triangle.
  For example, given k = 3,
  Return [1,3,3,1].
  Note:
  Could you optimize your algorithm to use only O(k) extra space?
*/
#include <vector>

class Solution
{
 public:
  std::vector<int> getRow(int rowIndex)
  {
    long long curVal = 1;
    std::vector<int> ret;
    ret.push_back(1);
    for( int i = 1 ; i < rowIndex + 1 ; ++ i)
    {
      curVal *= ( rowIndex - i + 1) ;
      curVal /= i;
      ret.push_back(curVal);
    }
    return ret;
  }
};
