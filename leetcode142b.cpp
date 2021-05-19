// 链表中的环的入口 节点
// 算法2的关键点
// 通过快(速度为慢的2倍）慢指针法，如果存在循环，快慢指针会在环内相遇
// 2(x+y) = x + y + z+ y,  x= z, z是快慢指针相遇点到环起点的距离
// 此时，x = head, y = meet, 都依次向前移动,就会相遇,此位置是环的起点
// 空间复杂度o(1),时间复杂度o(N)

 #include <iostream>

 struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x):val(x),next(NULL){} // constructor
 };

 class Solution {
   public: ListNode *detectCycle(ListNode *head) {
     ListNode *fast = head; // 指向料表头节点
     ListNode *slow = head;
     ListNode *meet = NULL; // 指向空

     //寻找快慢指针相遇节点
     while(fast && fast->next ){
       slow = slow->next;
       fast= fast->next->next;
       if(fast == slow) {
         meet = fast;
         break;
       }
     }

    while(head && meet && head!= meet ){
      head = head->next;
      meet = meet->next;
    }
    return meet;
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