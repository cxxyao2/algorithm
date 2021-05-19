// 两个已经排序的链表的合并
// 总是获得两个链表中的最小值,归并算法
// 从两个链表的head开始往前推,比较两个链表节点的值，获得最小的

#include <iostream>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {} // constructor
};

class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode temp(0);      // 临时头节点
    ListNode *ptr = &temp; // ptr指向temp
    while (l1 && l2)
    {
      if (l1->val < l2->val)
      {
        ptr->next = l1;
        l1 = l1->next;
      }
      else
      {
        ptr->next = l2;
        l2 = l2->next;
      }
      ptr = ptr->next;
    }
    if (l1)
    {
      ptr->next = l1;
    }
    if (l2)
    {
      ptr->next = l2;
    }
    return temp.next; // 函数最终返回合并后的链表头节点的地址
  }
};

int main()
{
  ListNode a(5);
  ListNode b(17);
  ListNode c(20);
  ListNode d(4);
  ListNode e(6);
  ListNode f(19);
  a.next = &b;
  b.next = &c;
  d.next = &e;
  e.next = &f;
  Solution solve;
  ListNode *result = solve.mergeTwoLists(&a, &d);
  while (result)
  {
    printf("%d\n", result->val);
    result = result->next;
  }

  return 0;
}