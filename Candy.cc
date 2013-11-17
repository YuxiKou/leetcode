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
    int n = ratings.size();
    if (n == 0) return 0;
    if (n == 1) return 1;
    std::vector<int> candies(n, 1);
    for (int i = 1; i <= n - 1; ++ i)
    {
      if (ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
    }
    for (int i = n - 2; i >= 0; -- i)
    {
      if (ratings[i] > ratings[i+1]) candies[i] = std::max(candies[i], candies[i+1] + 1);
    }
    int result = 0;
    for (int i = 0; i < n; ++ i) result += candies[i];
    return result;
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
