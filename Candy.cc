/*
  There are N children standing in a line. Each child is assigned a rating value.
  You are giving candies to these children subjected to the following requirements:
  Each child must have at least one candy.
  Children with a higher rating get more candies than their neighbors.
  What is the minimum candies you must give?
*/
#include <vector>
#include <iostream>
class Solution
{
 public:
  int candy(std::vector<int> &ratings)
  {
    bool isAsc = true;
    int length = 0;
    int sum = ratings.size();
    for( std::vector<int>::size_type i = 0 ; i < ratings.size() - 1 ; ++ i)
    {
      if(ratings[i+1] > ratings[i])
      {
        if(isAsc)
        {
          ++length;
          sum += length;
        }
        else
        {
          isAsc = true;
          length = 0;
        }
      }
      else if(ratings[i+1] < ratings[i])
      {
        if(isAsc)
        {
          isAsc = false;
          length = 0;
        }
        else
        {
          ++length;
          sum += length;
        }
      }
      else
      {
        sum += length;
      }
    }
    if(isAsc) sum += length;
    else sum += 1;
    return sum;
  }
};

int main()
{
  Solution sol;
  int array[] = {1,2,4,3,2,1};
  std::vector<int> input(array, array + sizeof(array)/sizeof(int));
  std::cout<<sol.candy(input)<<std::endl;
  return 0;
}
