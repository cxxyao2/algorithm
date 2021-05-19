 #include <iostream>

 struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x):val(x),next(NULL){} // constructor
 };
 
 int list_length(ListNode *head){ // 待求长度的链表头结点指针
  int length = 0; //存储链表长度
  while(head){
    length++;
    head = head->next;
  }
  return length;
 }

 ListNode *move_pointer(ListNode *head, int count) {
  // 链表头结点指针head与移动的结点数,返回移动后的指针
  for(int i=0;i<count;i++){
    head = head->next;
  } 
  return head;
 };

 class Solution {
   public: ListNode *getIntersectionNode(ListNode *headA,ListNode *headB) {
     int lengthA = list_length(headA);
     int lengthB = list_length(headB);
     printf("%d\n lengthB is %d\n",lengthA, lengthB);
     if(lengthA > lengthB) {
       headA = move_pointer(headA, lengthA - lengthB);
       
     } else {
       headB = move_pointer(headB, lengthB - lengthA);
     }
     ListNode *result = NULL; //存储交点位置
     while(headA && headB) {
       if(headA == headB){
         result = headA;
         break;
       }
       headA = headA->next;
       headB = headB->next;
     }
     return result;
   }
 };
 
 int main(){
   ListNode a(4);
   ListNode b(1);
   ListNode c(5);
   ListNode d(0);
   ListNode e(1);
   ListNode f(8);
   ListNode g(4);
   ListNode h(5);
   a.next = &b;
   b.next = &f;
   c.next = &d;
   d.next = &e;
   e.next = &f;
   f.next = &g;
   g.next = &h;
   Solution solve;
   ListNode *result = solve.getIntersectionNode(&a, &c);
   printf("%d\n",result->val);
   return 0;
 }