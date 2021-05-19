// 跳跃游戏。有多个格子，每个格子中写的可以跳跃的最大步数不同
// 判断是否可以跳跃到尾部
// 核心：max(前面位置中的index+ 可以跳远步数） >= index.
#include <vector>
using namespace std;

class Solution {
  public:
  bool canJump(vector<int> &nums) {
    vector<int> jump; // 每个格子中可以跳跃到的最远位置
    for(int i=0;i< nums.size(); i++) {
      jump.push_back(i+nums[i]);
    }
    int index = 0;
    int max_jump =jump[0];
    // 前面最远位置能到达当前位置,才能继续前进;否则,失败
    while(index < jump.size() && index<= max_jump) {
      if(max_jump < jump[index]) {
        max_jump = jump[index];
        }
        index++;
      }
      if(index == jump.size()) {
        return true;
      }
      return false;
    }
  };

  int main() {
    // nums = [2,4,2,3,1,0,0]
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    Solution solution;
    printf("%d\n", solution.canJump(nums));
    return 0;

  }
