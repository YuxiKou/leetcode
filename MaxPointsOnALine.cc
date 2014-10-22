#include <vector>
#include <unordered_map>

using namespace std;

struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
 public:
  int maxPoints(vector<Point> &points) {
    if(points.size() == 0)
    {
      return 0;
    }
    int maxPoints = 1;
    int result = 0;
    for(int i = 0 ;i < points.size(); ++i)
    {
      unordered_map<double, int> umap;
      int samePoint = 0;
      for(int j = i + 1; j < points.size(); ++ j)
      {
        double slope = 0;
        if(points[i].x == points[j].x)
        {
          if(points[i].y == points[j].y)
          {
            ++samePoint;
            continue;
          }
          else
          {
            slope = std::numeric_limits<double>::infinity();
          }
        }
        else
        {
          slope = 1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x);
        }
        if(umap.find(slope) == umap.end())
        {
          umap.insert(unordered_map<double, int>::value_type(slope, 2));
        }
        else
        {
          ++umap[slope];
        }
        if(umap[slope] > maxPoints)
        {
          maxPoints = umap[slope];
        }
      }
      if(result < maxPoints + samePoint) result = maxPoints + samePoint;
    }
    return result;
  }
};
