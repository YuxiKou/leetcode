/*
  Say you have an array for which the ith element is the price of a given stock on day i.
  Design an algorithm to find the maximum profit. You may complete at most two transactions.
  You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
#include <vector>

using namespace std;

class Solution
{
 public:
  int maxProfit(vector<int> &prices)
  {
    int size = prices.size();
    if(size < 2) return 0;
    int min = prices[0];
    int max = prices[size-1];
    vector<int> maxPrice(size, 0);
    int ret = 0;
    for(int i = 1; i < size; ++i)
    {
      if(prices[i] < min) min = prices[i];
      maxPrice[i] = std::max(maxPrice[i-1], prices[i] - min);
    }
    ret = maxPrice[size-1];
    for(int i = size - 2; i >= 0; --i)
    {
      int localMax = maxPrice[i] + max - prices[i+1];
      if(localMax > ret) ret = localMax;
      if(prices[i] > max) max = prices[i];
    }
    return ret;
  }
};
