/*
  Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
  Find all unique triplets in the array which gives the sum of zero.

  Note:

  Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
  The solution set must not contain duplicate triplets.
  For example, given array S = {-1 0 1 2 -1 -4},

  A solution set is:
  (-1, 0, 1)
  (-1, -1, 2)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<vector<int> > threeSum(vector<int> &num)
  {
    vector<vector<int> > ret;
    if (num.size() < 3) return ret;
    sort(num.begin(), num.end()); //O(NlogN)
    for( vector<int>::size_type i = 0 ; i < num.size() - 2; ++i )
    {
      if (i > 0 && num[i] == num[i-1]) continue;
      vector<int>::size_type start = i + 1;
      vector<int>::size_type end = num.size() - 1;
      while(start < end)
      {
        int sum = num[i] + num[start] + num[end];
        if (sum == 0)
        {
          int tuple[] = { num[i], num[start], num[end] };
          vector<int> oneTuple( tuple, tuple + sizeof(tuple) / sizeof(int));
          ret.push_back(oneTuple);
          do {++start;} while(start < end && num[start]==num[start-1]) ;
          do {--end;} while(start < end && num[end]==num[end+1]) ;
        }
        else if (sum > 0)
        {
          do {--end;} while(start < end && num[end]==num[end+1]) ;
        }
        else
        {
          do {++start;} while(start < end && num[start]==num[start-1]) ;
        }
      }
    }
    return ret;
  }
};
int main()
{
  Solution sol;
  vector<int> input;
  vector<vector<int> > output;
  input.push_back(-2);
  input.push_back(0);
  input.push_back(1);
  input.push_back(1);
  input.push_back(2);
  output = sol.threeSum(input);
  cout<<output.size()<<endl;
}
