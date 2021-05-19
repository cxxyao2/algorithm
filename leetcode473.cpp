// 火柴拼正方形
// 比如，长度为1，2，3的火柴各有4根，能否拼正方形？ 不能折断火柴
// 1,1,2,2,2, 3根2 和2个1的火柴，可以拼成一个长度为2的正方形
// 关键点： 1，所有火柴的长度求和--》除以4，得到正方形周长   
// 2，把火柴按照长度从大到小排序，依次放入想象中的4个桶
#include<iostream>  
#include <cstring>

#include <vector>
using namespace std;

class Solution {
  public: 
  bool makeSquare(vector<int> &nums) {
    if(nums.size() <4) {
      return false;
    }
    int sum = 0;
    for(int i=0;i<nums.size();i++) {
      sum += nums[i];
    }
    if(sum % 4) {
      return false;
    }
    sort(nums.rbegin(), nums.rend());

    int bucket[4] = {0};
    return backtrack(0,nums, sum/4, bucket);
  }


  private:
  // i 代表正在放置的火柴的下标 ,nums代表火柴的长度
  // edge代表计算好的正方形边长, bucket存储4个桶的高度
  bool backtrack(int i, vector<int> &nums, int edge, int bucket[]) {
    if(i>=nums.size()) { // 全部的火柴都放到了桶中
      return true;
    }

    for(int j=0;j<4;j++) {
      if(bucket[j] + nums[i] > edge) {
        continue;
      }
      bucket[j] += nums[i];  // nums[i]放入到j桶中
      if(backtrack(i+1, nums,edge,bucket)) {
        return true;  //下一个火柴放置成功就返回true

      }
      bucket[j] -= nums[i]; //讲num[i]从桶j中拿出

    }
    return false; // num[i]无法返回任何一个桶

  }

};

int main() {

  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(5);
  nums.push_back(5);
  //   nums.push_back(1);
  Solution solution;
  printf("%d\n", solution.makeSquare(nums)); // 1 ok 0 ng

  return 0;
}