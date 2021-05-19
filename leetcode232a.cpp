// 栈：先进后出， 队列：先进先出
// 栈的方法：push,pop，top.栈的pop是从原来的栈中移走的操作
// 用栈来实现队列的这些操作 push, peek , pop要移除, empty 
// 栈的数据全部弹出pop然后push到临时栈,临时栈再pop. 或者直接取顶部数据
// 方法1 借助临时栈，用完后临时栈销毁 时间复杂度o(N)

 #include <iostream>
 #include <stack> //STL 栈 stack
class MyQueue{
public:
  MyQueue(){

  }  

  void push(int x){
      data.push(x);
  }

// 从栈中移除
int pop(){
    std::stack<int> temp;
      while(!data.empty()){
          temp.push(data.top());
          data.pop();
      }
      int res = temp.top();
      temp.pop();
      while(!temp.empty()){
          data.push(temp.top());
          temp.pop();
      }
      return res;
}

// 返回队列头部元素的功能,但是不从队列中删除
  int peek(){
      std::stack<int> temp;
      while(!data.empty()){
          temp.push(data.top());
          data.pop();
      }
      int res = temp.top();
      while(!temp.empty()){
          data.push(temp.top());
          temp.pop();
      }
      return res;
  }

  bool empty(){
      return data.empty();
  }

private:
  std::stack<int> data; //
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