// 栈：先进后出， 队列：先进先出
// 栈的方法：push,pop，top.栈的pop是从原来的栈中移走的操作
// 用栈来实现队列的这些操作 push, peek , pop要移除, empty 
// 栈的数据全部弹出pop然后push到临时栈,临时栈再pop. 或者直接取顶部数据
// 方法2 借助双栈法，时间复杂度o(1)
// 输入栈完成push,输出栈完成pop和peek，输出栈的数据不需要弹回到输入
// 输出栈有数据就直接pop和peepk，没数据就把输入栈的数据全部弹到输出栈来

 #include <iostream>
 #include <stack> //STL 栈 stack
class MyQueue{
public:
  MyQueue(){

  }  

  void push(int x){
      input.push(x);
  }

// 从栈中移除
int pop(){
    std::stack<int> temp;
     if(output.empty()){
       while(!input.empty()){
         output.push(input.top());
          input.pop();
       }
     }
     int x= output.top();
     output.pop();
     return x;
}

// 返回队列头部元素的功能,但是不从队列中删除
  int peek(){
     if(output.empty()){
       while(!input.empty()){
         output.push(input.top());
          input.pop();
       }
     }
     return output.top();
  }

  bool empty(){
      return input.empty() && output.empty();
  }

private:
  std::stack<int> input; 
  std::stack<int> output;
}
;

int main(){
  MyQueue mq; 
  mq.push(1);
  mq.push(2);
  mq.push(3);
  printf("queue front item is %d\n", mq.peek());
  mq.pop();
  printf("queue front item is %d\n", mq.peek());
  return 0;
}