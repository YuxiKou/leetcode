/*
  Given an array of strings, return all groups of strings that are anagrams.
  Note: All inputs will be in lower-case.
*/
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution
{
 public:
  vector<string> anagrams(vector<string> &strs)
  {
    vector<string> ret;
    map<string, vector<string> > dict;
    for(vector<string>::iterator it = strs.begin(); it != strs.end(); ++it)
    {
      string oneStr = *it;
      sort(oneStr.begin(), oneStr.end());
      dict[oneStr].push_back(*it);
    }
    for(map<string, vector<string> >::iterator it = dict.begin(); it != dict.end(); ++ it)
    {
      if(it->second.size() > 1)
      {
        for(vector<string>::iterator st = it->second.begin(); st != it->second.end(); ++st)
        {
          ret.push_back(*st);
        }
      }
    }
    return ret;
  }
};
int main()
{
  return 0;
}
