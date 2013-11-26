/*
  Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

  Note:
  Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
  The solution set must not contain duplicate quadruplets.
  For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

  A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
 private:
  class Pair
  {
   public:
    int _num1;
    int _num2;
    int _sum;
    int _ind1;
    int _ind2;
    Pair(int num1, int num2, int ind1, int ind2)
    {
      _num1 = num1;
      _num2 = num2;
      _ind1 = ind1;
      _ind2 = ind2;
      _sum = num1 + num2;
    }
    bool operator<(Pair compareTo)
    {
      return _sum < compareTo._sum;
    }
  };
 public:
  vector<vector<int> > fourSum(vector<int> &num, int target)
  {
    vector<Pair> pairs;
    vector<vector<int> > ret;
    int n = num.size();
    if(n < 4) return ret;
    for(int i = 0; i < n; ++ i)
    {
      for(int j = i + 1; j < n; ++ j)
      {
        pairs.push_back(Pair(num[i], num[j], i, j));
      }
    }
    std::sort(pairs.begin(), pairs.end());
    return ret;
  }
};
int main()
{
  Solution sol;
  return 0;
}
