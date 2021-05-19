// 判断是否为合法的出栈序列
// 入栈的元素可以立刻弹出
// 弹出的元素形成一个栈A，剩下的栈B+等待入栈的元素C,
// 如果A顶部的元素与B的相同，都弹出，然后C中元素进到栈B
// A,B的元素都消除完，就是合法的出栈序列，如不为空，就不是
// 核心：利用栈stack和可以直接索引位置的队列vector

// vector 向量容器简介
// 按照严格的线性顺序排列,可以通过系列中的位置访问元素
// vector(),push_back,insert, erase, pop_back(),clear(),at(),back(),empty()

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
  {
    // pushed 入栈序列 popped 出栈序列
    std::stack<int> S; //模拟入栈与出栈的过程
    int index = 0;     // 当前正在判断的出栈序列元素的下标
    for (int i = 0; i < pushed.size(); i++)
    {
      S.push(pushed[i]); // 每遍历一个元素即将该元素push 进入栈s
      while (!S.empty() && popped[index] == S.top())
      { // 栈顶与出栈序列的队头是否相等
        // 如果相等,同时弹出栈顶元素与队列头部元素
        // 直到栈空或者栈顶与队列头部元素不同
        S.pop(); //弹出栈顶元素
        index++; // 弹出队列头部元素
      }
    }

    if (!S.empty()) // 栈不为空，则表示出栈序列不合法
    {
      return false;
    }
    return true;
  }
};

int main()
{
  vector<int> pushed; //入栈序列
  vector<int> popped; //出栈序列
  pushed.push_back(1);
  pushed.push_back(2);
  pushed.push_back(3);
  pushed.push_back(4);
  pushed.push_back(5);

  popped.push_back(3);
  popped.push_back(2);
  popped.push_back(3);
  popped.push_back(4);
  popped.push_back(5);

  Solution solve;
  printf("%d\n", solve.validateStackSequences(pushed, popped));
  return 0;
}