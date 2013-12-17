/*
  Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

  Only one letter can be changed at a time
  Each intermediate word must exist in the dictionary
  For example,

  Given:
  start = "hit"
  end = "cog"
  dict = ["hot","dot","dog","lot","log"]
  As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
  return its length 5.

  Note:
  Return 0 if there is no such transformation sequence.
  All words have the same length.
  All words contain only lowercase alphabetic characters.
*/
#include <string>
#include <unordered_set>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
 public:
  int ladderLength(string start, string end, unordered_set<string> &dict)
  {
    int n = start.length();
    if(n == 0 || n != (int)end.length()) return 0;

    int result = 0;
    queue<string> bfsQueue;

    bfsQueue.push(start);
    bfsQueue.push("");
    while(!bfsQueue.empty())
    {
      string curStr = bfsQueue.front();
      bfsQueue.pop();
      if(curStr == "")
      {
        if(!bfsQueue.empty())
        {
          ++result;
          bfsQueue.push("");
        }
      }
      else
      {
        for(int i = 0; i < n; ++ i)
        {
          char curChar = curStr[i];
          for(char j = 'a'; j <= 'z'; ++ j)
          {
            curStr[i] = j;
            if(curStr == end) return result + 2;
            if(dict.find(curStr) != dict.end())
            {
              bfsQueue.push(curStr);
              dict.erase(curStr);
            }
          }
          curStr[i] = curChar;
        }
      }
    }
    return 0;
  }
};
