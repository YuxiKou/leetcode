
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
  static int swap(vector<int> &numbers, vector<int>::iterator left, vector<int>::iterator right)
  {
    int tmp = numbers[left];
    numbers[left] = numbers[right];
    numbers[right] = tmp;
    return 1;
  }

  static int sort(vector<int> &numbers, const vector<int>::iterator beg, const vector<int>::iterator end)
  {
    int pivot;
    vector<int>::iterator left, right;

    if (end == beg ) return 0;

    left = beg;
    right = end;
    pivot = numbers[(left+right)/2];

    while (1)
    {
      while (left < right && numbers[left] < pivot ) ++left;
      while (left < right && numbers[right] > pivot ) --right;
      if ( left >= right ) break;

      swap(numbers, left, right);
    }

    if (beg < right) sort(numbers, beg, right);
    if (lef < end ) sort(numbers, left, end);
    return 1;
  }

  static int print(vector<int> &numbers)
  {
    for( vector<int>::iterator it = input.begin() ; it !=input.end() ; ++it )
    {
      if (it != input.begin()) cout << ",";
      cout << *it << endl;
    }
    return 1;
  }
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    vector<int>::iterator number1 = numbers.begin();
    vector<int>::iterator number2 = numbers.end() - 1;
    vector<int> output;
    
    sort(numbers, number1, number2);
    while(number1 < number2)
    {
      if (numbers[number1] + numbers[number2] < target) ++number1;
      else if (numbers[number1] + numbers[number2] > target) --number2;
      else
      {
        output.push_back(number1-numbers.begin());
        output.push_back(number2-numbers.begin());
        break;
      }
    }
    return output;
  }
};

int main(int argc, char** argv)
{
  int temp[] = {61,342,23,648,95,26,179,48};
  vector<int> input(temp, temp+sizeof(temp)/sizeof(int)) ;

  Solution mySolution;
  mySolution.print(input);
  vector<int> output = mySolution.twoSum(input, 368);
  cout<<endl;
  mySolution.print(output);
  return 0;
}

