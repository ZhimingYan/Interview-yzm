## 字节跳动C++

### 实习面试

1. 逆序对
2. 判断回文子串
3. 两个字符串的最长公共子串kmp
4. topk问题以及分析时间复杂度
5. 通过调用一个没有形参的函数，去改变调用函数里面的参数（涉及到函数压栈和ebp的问题）
6. 集合的子集

### 提前批

#### 一面

1. 项目
2. http服务，接收方如何判断数据接受完毕
3. 分别说说ARP、ICMP、TCP协议的理解
4. 介绍select、epoll的区别？ 
5. 介绍下泛洪？ 
6. 介绍下C++三种智能指针，三种的区别分别是什么？ 
7. c语言中static的用法？ 
8. tcp连接、断开的详细过程？每个过程的标志都有什么？ 
9. 平时如何调试程序？断点的原理是什么？
10. 链表对折

#### 二面

1. http请求的方法

2. http报文结构

3. 说几个http首部的字段？管线化是什么？怎么保证服务器按顺序返回？

4. 说下tcp的特点有哪些？详细讲tcp的一些机制？为什么需要这些机制？详细讲tcp报文首部？

5. 已知结构体类型和指向某个成员的指针，求结构体起始地址，例如：

   struct A {int a; int b;...;int c;...}；指向结构体变量a中c成员的指针是int *p。求a的地址？

6. 逆时针打印矩阵

7. 已知f()函数以概率p输出1，以概率1-P输出0。然后实现g()等概率的输出1和0:

     int g() 

     { 

     } 

     进一步通过刚实现的g()，实现等概率输出0-n的函数int h(int n): 

     int h(int n) 

     { 

     }

8. 实现Linux命令tail -f filename的函数？（需要检查参数和文件类型是否合格）

   int main(int argc, char* argv[])

   {

   }

#### 四面

1. 二叉树的右视角

