// 链表中的环的入口 节点
// 算法1的关键点
// 利用set来存储节点地址,如果在set中能找到,结束;找不到,就把当前节点地址插入set中
// set通过红黑树来实现,查找和插入一个值的时间复杂度是 o(logN), 
// 整个算法的时间复杂度是o(NlogN).因为需要用set来存储所有节点地址,空间复杂度是o(N)

// set 的方法 find. insert
 #include <iostream>
 #include <set>
 using namespace std;

 struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x):val(x),next(NULL){} // constructor
 };

 class Solution {
   public: ListNode *detectCycle(ListNode *head) {
     set<ListNode *> check_set;
     while(head){
       if( check_set.find(head) != check_set.end()){
         return head;
       } else{
         check_set.insert(head);
         head = head->next;
       }
     }
    return NULL;
   }
  };


  int main(){
   ListNode a(1);
   ListNode b(2);
   ListNode c(3);
   ListNode d(4);
   ListNode e(5);
   ListNode f(6);
   ListNode g(7);
   a.next = &b;
   b.next = &c;
   c.next = &d;
   d.next = &e;
   e.next = &f;
   f.next = &g;
   g.next = &c; // g节点指向c节点，形成环
   Solution solve;
   ListNode *result = solve.detectCycle(&a);
   printf("%x  %x\n", &c, result);
   return 0;
 }