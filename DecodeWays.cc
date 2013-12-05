/*
  A message containing letters from A-Z is being encoded to numbers using the following mapping:

  'A' -> 1
  'B' -> 2
  ...
  'Z' -> 26
  Given an encoded message containing digits, determine the total number of ways to decode it.
  For example,
  Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
  The number of ways decoding "12" is 2.
*/
#include <string>
#include <vector>

using namespace std;

class Solution
{
 public:
  int numDecodings(string s)
  {
    int length = s.length();
    if(length == 0 || s[0] == '0') return 0;
    vector<int> ways(length + 1, 0);
    ways[0] = ways[1] = 1;
    for(int i = 2; i < length + 1; ++i)
    {
      ways[i] = s[i-1] == '0' ? 0 : ways[i-1];
      if((s[i-2] == '1') || (s[i-2] == '2' && s[i-1] < '7')) ways[i] += ways[i-2];
      if(ways[i] == 0) return 0;
    }
    return ways[length];
  }
};
