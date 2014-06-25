/*Given a string, find the length of the longest substring without repeating characters.
  For example, the longest substring without repeating letters for "abcabcbb" is "abc",
  which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.*/

#include <iostream>
#include <string>

using namespace std;

const int C_SIZE = 256;

class Solution {
public:
  int lengthOfLongestSubstring(string s)
  {
    int length = s.length();
    int *maps = new int[C_SIZE];

    int curLen = 0;
    int curStart = 0;
    int maxLen = 0;
    int index = 0;

    for(int i = 0 ; i < C_SIZE ; ++ i )
    {
      maps[i] = -1;
    }

    for(int i = 0 ; i < length ; ++ i )
    {
      index = s.at(i);

      if (maps[index] > -1 && maps[index] >= curStart)
      {
        curLen = i - curStart;
        maxLen = maxLen > curLen ? maxLen : curLen;
        curStart = maps[index] + 1;
      }
      maps[index] = i;
    }
    curLen = length - curStart;
    maxLen = maxLen > curLen ? maxLen : curLen;
    return maxLen;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;
  string s ;
  cin>>s;
  cout<<"the value is " << sol.lengthOfLongestSubstring(s)  <<endl;
  return 0;
}
