/*
  Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
  You have the following 3 operations permitted on a word:
  a) Insert a character
  b) Delete a character
  c) Replace a character
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
 public:
  int minDistance(string word1, string word2)
  {
    int m = word1.size();
    int n = word2.size();
    if(m == 0) return n;
    if(n == 0) return m;
    vector<int> temp(n + 1, 5);
    vector<vector<int> > dist(m + 1, temp);
    cout<<dist.size()<<endl;
    cout<<dist[0].size()<<endl;
    cout<<dist[1].size()<<endl;
    cout<<dist[1][1]<<endl;
    for(int i = 0; i < m + 1; ++ i)
    {
      for(int j = 0; j < n + 1; ++ j)
      {
        if(i == 0 || j == 0) dist[i][j] = (i > j ? i : j);
        else if(word1[i-1] == word2[j-1]) dist[i][j] = dist[i-1][j-1];
        else dist[i][j] = min<int>(min<int>(dist[i-1][j], dist[i][j-1]), dist[i-1][j-1]) + 1;
      }
    }
    return dist[m][n];
  }
};
int main()
{
  Solution sol;
  cout<<sol.minDistance("a", "b")<<endl;
  return 0;
}
