// 给出n个左括号和n个右括号，打印出合理的组合
#include<iostream>  
#include <cstring>
 
#include <vector>
using namespace std;

class Solution {
  public:
  vector<string> generateParenthesis(int n) {
    vector<string> brackets;
    backtrack("", brackets, 0, 0, n);
    return brackets;
  }
  
  private: 
  void backtrack(string str, vector<string> &brackets,
  int left, int right ,int n) {
    if(str.size() == 2*n ){
      brackets.push_back(str);
      return;
    }
    if(left<n) {
      backtrack(str+"(",brackets,left+1,right,n);
    }
    if(right<left) {
      backtrack(str+")",brackets,left,right+1,n);
    }
  }
  };

  int main() {
    Solution solve;
    vector<string> brackets = solve.generateParenthesis(3);
    for(int i=0;i<brackets.size();i++) {
      printf("%s\n", brackets[i].c_str());
    }
    return 0;
  }