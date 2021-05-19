// x 轴上很多大小不一的气球，每个气球有两个X坐标(X1,X2)
// 向Y轴发射弓箭，可以同时射击到多个气球
// 最少需要多少弓箭
// 核心：先按照气球的左坐标X1排序，依次求交集；没有交集的，就需要新的弓箭
// 射击区间的右端点，大于等于本端点的左端点，有交集；小于左端点，新的区间
#include <algorithm>
#include <vector>
using namespace std;


bool cmp(const vector<int> &a, const vector<int> &b)
{
  return a[0] < b[0];
}

class Solution
{
public:
  int findMinArrowShots(vector<vector<int> > &points)
  {
    if (points.size() == 0)
    { //特殊的空数据判断
      return 0;
    }

    std::sort(points.begin(), points.end(), cmp); // 对气球从左到右排序
    int arrow_count = 1;
    int interval_right = points[0][1]; // 第一个气球的右端点
    for (int i = 1; i < points.size(); i++)
    {
      if (interval_right >= points[i][0])
      {
        if (interval_right > points[i][1])
        {
          interval_right = points[i][1];
        }
      }
      else
      {
        arrow_count++;
        interval_right = points[i][1];
      }
    }
    return arrow_count;
  }
};

int main()
{
  vector<vector<int> > points;
  vector<int> p0, p1, p2, p3;
  p0.push_back(10);
  p0.push_back(10);
  points.push_back(p0);

  p1.push_back(2);
  p1.push_back(8);
  points.push_back(p1);

  p2.push_back(1);
  p2.push_back(6);
  points.push_back(p2);

  p3.push_back(7);
  p3.push_back(12);
  points.push_back(p3);

  Solution solution;
  printf("%d\n", solution.findMinArrowShots(points));

  return 0;
}