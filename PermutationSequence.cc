/*
  The set [1,2,3,…,n] contains a total of n! unique permutations.

  By listing and labeling all of the permutations in order,
  We get the following sequence (ie, for n = 3):

  "123"
  "132"
  "213"
  "231"
  "312"
  "321"
  Given n and k, return the kth permutation sequence.

  Note: Given n will be between 1 and 9 inclusive.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
 public:
  string getPermutation(int n, int k)
  {
    if(n == 1) return "1";
    vector<bool> nums(n, false);
    int permute = 1;
    for(int i = 0; i < n ; ++ i)
    {
      permute *= (i + 1);
    }
    --k;
    string ret = "";
    for(int i = 0; i < n; ++ i)
    {
      permute /= (n-i);
      int num = k / permute;
      int j;
      for(j = 0; j < n; ++ j)
      {
        if(nums[j] == false) -- num;
        if(num < 0)
        {
          nums[j] = true;
          break;
        }
      }
      ret += '1' + j;
      k %= permute;
    }
    return ret;
  }
};
int main()
{
  Solution sol;
  cout<<sol.getPermutation(2, 1)<<endl;
}
