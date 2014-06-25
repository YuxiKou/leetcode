
/*
  given an array of integers, find two numbers such that they add up to a specific target number.
  The function twoSum should return indices of the two numbers such that they add up to the target,
  where index1 must be less than index2. Please note that your
  returned answers (both index1 and index2) are not zero-based.
  You may assume that each input would have exactly one solution.
  Input: numbers={2, 7, 11, 15}, target=9
  Output: index1=1, index2=2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    vector<int> returnValue;
    map<int,int> hash;
    for (vector<int>::size_type i = 0; i < numbers.size(); ++i)
    {
      if (hash[target - numbers[i]] > 0)
      {
        returnValue.push_back(hash[target - numbers[i]]);
        returnValue.push_back(i+1);
        return returnValue;
      }
      else
      {
        hash[numbers[i]] = i + 1;
      }
    }
    return returnValue;
  }
};

int main(int argc, char** argv)
{
  Solution mySolution;
  int inputAry[] = {5,74,25,12,39,85,99,1};
  vector<int> input(inputAry,inputAry+sizeof(inputAry)/sizeof(int));
  vector<int> index = mySolution.twoSum(input,100);
  if (index.size()>0)
  {
    cout<<index[0]<<" "<<index[1]<<endl;
  }
  return 0;
}


