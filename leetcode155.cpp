// 给标准栈加一个getMin函数,在每次pop一个元素后,得到栈中元素的最小值
// 设置两个栈，数据栈和最小值栈，用空间来换时间
// 最小值栈存储的，是对应数据栈每个元素push时，数据栈的最小值
// 数据栈(从顶部最底部) 5 -8 6 -2, 最小值栈 -8 -8 -2 -2.
// 空间复杂度o(N),时间复杂度o(1)
#include <stack> // STL stack
#include <iostream>

class MinStack
{
public:
  MinStack() {}
  int top()
  {
    return data.top();
  }
  int getMin()
  {
    return mins.top();
  }
  void push(int x)
  {
    data.push(x);
    if (!mins.empty() && x > mins.top())
    {
      x = mins.top();
    }
    mins.push(x);
  }
  void pop()
  {
    data.pop();
    mins.pop();
  }

private:
  std::stack<int> data; // 数据栈
  std::stack<int> mins; //最小值栈
};

int main()
{
  MinStack ms;
  ms.push(-3);
  printf("top=[%d]\n", ms.top());
  printf("getMin=[%d]\n\n", ms.getMin());
  ms.push(6);
  printf("top=[%d]\n", ms.top());
  printf("getMin=[%d]\n\n", ms.getMin());
  ms.push(-8);
  printf("top=[%d]\n", ms.top());
  printf("getMin=[%d]\n\n", ms.getMin());
  ms.push(5);
  printf("top=[%d]\n", ms.top());
  printf("getMin=[%d]\n\n", ms.getMin());
  ms.pop();
  printf("top=[%d]\n", ms.top());
  printf("getMin=[%d]\n\n", ms.getMin());
  return 0;
}