/*
  Implement strStr().
  Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
  K-M-P algorithm:
  http://billhoo.blog.51cto.com/2337751/411486
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
 public:
  char *strStr(char *haystack, char *needle)
  {
    int hCount = 0, nCount = 0;
    while(haystack[hCount] != 0) ++hCount;
    while(needle[nCount] != 0) ++nCount;
    if(hCount < nCount) return NULL;
    if(nCount == 0) return haystack;

    vector<int> partMatch = buildPartialMatchTable(needle, nCount);
    for (int i = 0; i < hCount - nCount + 1; ++i)
    {
      int j;
      for (j = 0; j < nCount; ++j)
      {
        if(needle[j] != haystack[i+j])
        {
          i += j - partMatch[j] - 1;
          break;
        }
      }
      if(j == nCount) return haystack+i;
    }
    return NULL;
  }
  vector<int> buildPartialMatchTable(char *needle, int n)
  {
    vector<int> result(n + 1, 0);
    int longestPrefix = 0;
    result[0] = -1;
    for(int i = 2; i < n + 1; ++ i)
    {
      while(longestPrefix > 0 && needle[longestPrefix] != needle[i-1]) longestPrefix = result[longestPrefix];
      if(needle[longestPrefix] == needle[i-1]) ++longestPrefix;
      result[i] = longestPrefix;
    }
    return result;
  }
};
int main()
{
  Solution sol;
  char haystack[] = "mississippi";
  char needle[] = "issip";
  cout<<sol.strStr(haystack, needle)<<endl;
}
