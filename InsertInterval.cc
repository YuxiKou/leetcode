/*
  Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
  You may assume that the intervals were initially sorted according to their start times.

  Example 1:
  Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

  Example 2:
  Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

  This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/
#include <iostream>
#include <vector>

using namespace std;

struct Interval
{
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
 public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
  {
    vector<Interval> ret;
    vector<Interval>::size_type i;
    for(i = 0; i < intervals.size(); ++ i)
    {
      if(intervals[i].start > newInterval.end) break;
      if(intervals[i].end < newInterval.start)  ret.push_back(intervals[i]);
      else
      {
        if(intervals[i].start < newInterval.start) newInterval.start = intervals[i].start;
        if(intervals[i].end > newInterval.end) newInterval.end = intervals[i].end;
      }
    }
    ret.push_back(newInterval);
    while(i < intervals.size())
    {
      ret.push_back(intervals[i]);
      ++i;
    }
    return ret;
  }
};
