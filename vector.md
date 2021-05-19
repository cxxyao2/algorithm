# vector 向量及 namespace std 简介

#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

vector<int>obj;//创建一个向量存储容器 int
obj.pop_back();

1.push_back 在数组的最后添加一个数据

2.pop_back 去掉数组的最后一个数据

3.at 得到编号位置的数据

4.begin 得到数组头的指针

5.end 得到数组的最后一个单元+1 的指针

6．front 得到数组头的引用

7.back 得到数组的最后一个单元的引用

8.max_size 得到 vector 最大可以是多大

9.capacity 当前 vector 分配的大小

10.size 当前使用数据的大小

11.resize 改变当前使用数据的大小，如果它比当前使用的大，者填充默认值

12.reserve 改变当前 vecotr 所分配空间的大小

13.erase 删除指针指向的数据项

14.clear 清空当前的 vector

15.rbegin 将 vector 反转后的开始指针返回(其实就是原来的 end-1)

16.rend 将 vector 反转构的结束指针返回(其实就是原来的 begin-1)

17.empty 判断 vector 是否为空

18.swap 与另一个 vector 交换数据
