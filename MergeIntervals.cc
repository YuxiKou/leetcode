/*
  Given a collection of intervals, merge all overlapping intervals.
  For example,
  Given [1,3],[2,6],[8,10],[15,18],
  return [1,6],[8,10],[15,18].
*/
#include <vector>

using namespace std;

struct Interval
{
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool compare(const Interval &int1, const Interval &int2)
{
  return int1.start < int2.start;
}

class Solution
{
 public:
  vector<Interval> merge(vector<Interval> &intervals)
  {
    int size = intervals.size();
    if(size < 2) return intervals;
    sort(intervals.begin(), intervals.end(), compare);
    vector<Interval> result;
    int i = 0;
    while(i < size)
    {
      result.push_back(intervals[i++]);
      while(i < size && intervals[i].start <= result.back().end)
      {
        result.back().end = max(intervals[i++].end, result.back().end);
      }
    }
    return result;
  }
};
