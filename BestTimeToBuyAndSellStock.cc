/*
  Say you have an array for which the ith element is the price of a given stock on day i.
  If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/
#include <vector>

class Solution
{
 public:
  int maxProfit(std::vector<int> &prices)
  {
    if(prices.size() == 0 ) return 0;
    int min = prices[0];
    int maxDiff = 0;
    for(std::vector<int>::size_type i = 1 ; i < prices.size(); ++i)
    {
      if(prices[i] < min) min = prices[i];
      if(prices[i] - min > maxDiff) maxDiff = prices[i] - min;
    }
    return maxDiff;
  }
};

