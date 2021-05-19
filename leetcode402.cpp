// 从 一万位的大数字中删除K个数字，使它最小
// 核心：贪心算法 1，从最高位开始删除
// 2，从最高位开始，依次入栈，
// 3,删除栈顶数字， 满足3个条件 
// 3-1,栈不空 3-2还没有删除够K个数字
// 3-3 当前栈顶数字大于此时正在遍历的数字，否则入栈
// 如果遍历完，删除的数字还是小于K，那么，从栈顶到栈底进行删除
// 用字符串存储这个一万位的大数字  string num
#include <stack> // STL stack
#include <iostream>
using namespace std;


class Solution {
  public:
  string removeKdigits(string num, int k) {
    stack<char> digit; //初始化栈
    string result=""; // 存储结果的字符串
    for( int i=0; i<num.length();i++) {
      while(!digit.empty() && digit.top() >num[i] && k>0) {
        digit.pop();
        k--;
      }
      // 保证结果的最高位不以0开头，栈为空时，0不入栈
      if(num[i] == '0' && digit.empty()) {
        continue;
      }
      digit.push(num[i]);
    }

    while(!digit.empty() && k>0){
      digit.pop();
      k--;
    }

    while(!digit.empty()){  // 将栈中剩下的数字，从栈顶到栈底综合
      result += digit.top();
      digit.pop();
    }

// 由于栈底是最高位，栈底是最低位，使用reverse函数进行翻转
    reverse(result.begin(), result.end());
    if(result=="") {
      result = "0";
    }

    return result;


  }
};

int main(){
  Solution solution;
  cout << solution.removeKdigits("142219",3) << endl;
  cout << solution.removeKdigits("123456",3) << endl;
  cout << solution.removeKdigits("100305",1) << endl;
  return 0;

}