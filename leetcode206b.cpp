// 链表逆序
// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL
// 方法2 头插法
#include <iostream>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {} // constructor
};

void list_print(ListNode *head, const char *name)
{
  printf("%s:", name); // 打印字符串name
  // head 为空,打印null, 并返回
  if (!head)
  {
    printf("NULL\n");
    return;
  }
  while (head)
  {
    printf("[%d]", head->val);
    head = head->next;
  }
  printf("\n");
}

int main()
{
  ListNode a(1);
  ListNode b(2);
  ListNode c(3);
  ListNode d(4);
  ListNode e(5);

  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;

  ListNode *head = &a; // 指向链表的头结点a
  ListNode temp(0);    // 新链表头结点
  ListNode *next = NULL;
  list_print(head, "old_list");

  while (head)
  {
    next = head->next;
    head->next = temp.next;
    temp.next = head;
    head = next;
  }
  printf("the result is :\n");
  list_print(temp.next, "reverse_list");
  list_print(head, "old_list");
}