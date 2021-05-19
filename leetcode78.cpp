// 找出一个给定数组的所有子集，如123的子集有8个,[] 1 12 123 13 2 23 3 
#include <vector>
using namespace std;
class Solution {
  public:
  vector<vector<int> > subsets(vector<int> &nums) {
    vector<vector<int> > sets;
    vector<int> subset;
    sets.push_back(subset); // 将空集加入到sets
    backtrack(0,nums,subset,sets); // 回溯法计算各个子集
    return sets; // 返回最后的集合
  }
  
  private:
  void backtrack(int i, // 递归时访问的数组元素下标
  vector<int> &nums,  // 存储给定集合中的元素
  vector<int> &subset,  //  每次递归生成的自己
  vector<vector<int> > &sets  // 存储最终生成的所有子集
  ) {
    if(i >=nums.size()) {
      return;
    }
    subset.push_back(nums[i]);
    sets.push_back(subset);
    backtrack(i + 1, nums, subset, sets);

    subset.pop_back();
    backtrack(i + 1, nums, subset, sets);

  } 
};



int main(){
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
   // nums.push_back(4);
  Solution solve;
  vector<vector<int> > sets = solve.subsets(nums);
  for(int i=0; i< sets.size(); i++) {
    if(sets[i].size()== 0)  {
      printf("[]");
    }
    for(int j=0; j<sets[i].size();j++) {
      printf("[%d]",sets[i][j]);
    }
    printf("\n");

  }
  return 0;

}