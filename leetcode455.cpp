// 一堆大小不同糖果，尽量满足多的孩子，每个孩子对糖果大小的需求不同
// 要点1：对糖果和孩子的需求排序
// 要点2: 尽量用最小糖果满足需求，把大糖果留给需求大的孩子
// 要点3:不能满足低需求的糖果，肯定页不能满足高需求
// 使用可以按照索引定位的vector
#include <vector>
#include <algorithm> // 调用sort需要引用头文件algorithm
using namespace std;
class Solution
{
public:
  int findcontentchildren(vector<int> &g, vector<int> &s)
  {
    sort(g.begin(), g.end()); // 孩子需求从小到大排序
    sort(s.begin(), s.end()); // 糖果大小从小到大排序
    int child = 0;            // 已经满足的孩子的个数
    int candy = 0;            // 已经使用的糖果的个数
    while (candy < s.size() && child < g.size())
    {
      if (s[candy] > g[child])
      {
        child++;
      }
      candy++;
    }
    return child; // 返回得到满足的孩子的个数
  }
};

int main()
{
  Solution solve;
  int child[] = {6, 11, 3, 10, 16, 10};
  int candy[] = {7, 2, 21, 4, 9};
  vector<int> g(child, child + 6);
  vector<int> s(candy, candy + 5);
  printf("%d\n", solve.findcontentchildren(g, s));
  return 0;
}