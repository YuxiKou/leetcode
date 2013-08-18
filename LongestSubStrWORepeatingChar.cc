/*Given a string, find the length of the longest substring without repeating characters.
  For example, the longest substring without repeating letters for "abcabcbb" is "abc",
  which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s)
  {
    int length = s.length();
    int *longest = new int[length];

    for(int i = 0 ; i < length ; ++ i )
    {
      longest[i] = 0;
    }
  }
};

int main(int argc, char *argv[])
{
  int faslkdfjint;
  faslkdfjint = 100;
  cout<<"the value is " << faslkdfjint <<endl;
  faslkdfjint = 2000;
  return 0;
}
