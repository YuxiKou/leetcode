
/*
  Given an array of integers, find two numbers such that they add up to a specific target number.
  The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
  You may assume that each input would have exactly one solution.
  Input: numbers={2, 7, 11, 15}, target=9
  Output: index1=1, index2=2
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  static vector<int> sort(vector<int> &numbers, vector<int>::size_type beg, vector<int>::size_type end)
  {
    for( vector<int>::iterator it = numbers.begin() ; it != numbers.end() ; ++ it )
      

  }
  static vector<int> twoSum(vector<int> &numbers, int target)
  {
    
  }
};

int main(int argc, char** argv)
{
  int temp[] = {1,2,3,4,5,6,7,8};
  vector<int> input(temp, temp+sizeof(temp)/sizeof(int)) ;

  Solution mySolution;

  for( vector<int>::iterator it = input.begin() ; it !=input.end() ; ++it )
    cout << *it << endl;
  return 0;
}

