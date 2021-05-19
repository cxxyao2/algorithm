// 一个链表的划分，给出一个值X，小于X的，在前面，大于X的,在后面,不改变在原始链表中出现的顺序
// 2 1 5  4 3 0 null
// 合并后,如果X=3
// 2 1 0 5 4 3 null
// 核心是用两个头来分别记录大于X和小于X的，再合并,
// 空间复杂度是o(1),时间复杂度是o(n)

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
  ListNode *partition(ListNode *head, int x)
  {
    ListNode smaller_head(0); // 初始化头节点
    ListNode greater_head(0); // 初始化头节点
    ListNode *smaller = &smaller_head;
    ListNode *greater = &greater_head;
    while (head)
    {
      if (head->val < x)
      {
        smaller->next = head; // 将当前节点连接到smaller连接的尾部
        smaller = head;       // 将smaller指向当前节点
      }
      else
      {
        greater->next = head;
        greater = head;
      }
      head = head->next; // 移动next指针
    }
    smaller->next = greater_head.next;
    greater->next = NULL;
    return smaller_head.next;
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
  c.next = &d;
  d.next = &e;
  e.next = &f;
  Solution solve;
  ListNode *result = solve.partition(&a, 19);
  while (result)
  {
    printf("%d\n", result->val);
    result = result->next;
  }

  return 0;
}