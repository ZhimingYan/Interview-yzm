## 字节跳动C++

### 实习面试

1. 逆序对
   - 普通做法
   - 归并
2. 判断回文子串
3. 两个字符串的最长公共子串kmp
4. topk问题以及分析时间复杂度
5. 通过调用一个没有形参的函数，去改变调用函数里面的参数（涉及到函数压栈和ebp的问题）
6. 集合的子集

### 提前批

#### 一面

1. 项目

2. http服务，接收方如何判断数据接受完毕

   - HTTP协议的服务端响应报文里有Content-Length字段，明确了报文的长度。客户端应该是通过这个来判断的
   - 但是不是所有的都会有这个字段，此时会有
     - 传输完毕就关闭connection
     - http1.1没有content-Length,但是 Transfer-Encoding: chunked，最后一个chunk的length==0

3. 分别说说ARP、ICMP、TCP协议的理解

   ARP:地址解析协议，将ip地址转化为链路层地址的机制（ARP 只为同一子网上的节点解析 IP 地址， DNS 为因特网中任何地方的主机解析主机名）

   ICMP:用于主机和路由器彼此交互网络层信息。最典型的用途是差错报告，但其用途不仅仅限于此(如数据源抑制，用于拥塞控制)

4. 介绍select、epoll的区别？ 

   - 内置数组类型使得select的最大文件数受限最大文件描述数

   - 每次调用select时都要重新初始化描述符集，将fd从用户态拷贝到内核态，调用之后都需要将fd从内核态拷贝到用户态

   - 轮训排查当文件的描述符号的个数很多时，效率很低，而epoll只返回状态发生变化的文件描述符

     LT模式
     LT(level triggered)是缺省的工作方式，并且同时支持block和no-block socket.在这种做法中，内核告诉你一个文件描述符是否就绪了，然后你可以对这个就绪的fd进行IO操作。如果你不作任何操作，内核还是会继续通知你的。

     ET模式
     ET(edge-triggered)是高速工作方式，只支持no-block socket。在这种模式下，当描述符从未就绪变为就绪时，内核通过epoll告诉你。然后它会假设你知道文件描述符已经就绪，并且不会再为那个文件描述符发送更多的就绪通知，直到你做了某些操作导致那个文件描述符不再为就绪状态了(比如，你在发送，接收或者接收请求，或者发送接收的数据少于一定量时导致了一个EWOULDBLOCK 错误）。但是请注意，如果一直不对这个fd作IO操作(从而导致它再次变成未就绪)，内核不会发送更多的通知(only once)

     ET模式在很大程度上减少了epoll事件被重复触发的次数，因此效率要比LT模式高。epoll工作在ET模式的时候，必须使用非阻塞套接口，以避免由于一个文件句柄的阻塞读/阻塞写操作把处理多个文件描述符的任务饿死。

5. 介绍下泛洪？

   SYN Flood 就是用户向服务器发送报文后突然死机或掉线，那么服务器在发出应答报文后就无法收到客户端的确认报文（第三次握手无法完成），这时服务器端一般会重试并等待一段时间后再丢弃这个未完成的连接。一个用户出现异常导致服务器的一个线程等待一会儿并不是大问题，但恶意攻击者大量模拟这种情况，服务器端为了维护数以万计的半连接而消耗非常多的资源，结果往往是无暇理睬客户的正常请求，甚至崩溃。从正常客户的角度看来，网站失去了响应，无法访问。

   具体的解释

   SYN Flood是DDos攻击的其中一种形式，其原理是:在TCP连接初始化的时候需要进行三次握手（见图1和图2），攻击者在第一次握手的数据表里面，通过伪造"Source Address"(见图3)，让服务器(接收端)在进行第二次握手的时候，将确认包发向一个伪造的IP地址，由于IP地址是伪造的，因此服务器端迟迟等不到第三次的确认包，导致服务器打开了大量的`SYNC_RECV`半连接。

   

6. 介绍下C++三种智能指针，三种的区别分别是什么？ 

   shared指针，共享式拥有，可以多个指针指向相同的对象，该对象和起相关资源会在最后一个引用被摧毁时释放

   unique指针 ，实现一个独占式拥有，同一时间内只有一个智能指针可以指向该对象，你可以移交控制权，它对于避免内存泄露非常有用

   weak指针，你可以共享但是不拥有某个对象，一旦最后一个对象失去了所有权后weak_ptr 都会自动成空（empty）。因此，在default 和 copy 构造函数之外， weak_ptr 只提供 “接受一个 shared_ptr” 的构造函数。• 可打破环状引用（cycles of references，两个其实已经没有被使用的对象彼此互指，使之看似还在“被使用” 的状态）的问题

7. c语言中static的用法？ 

   - 全局变量只能在本文件中使用
   - 局部静态变量分配在数据段上
   - 对一个类中的成员变量和成员函数，该成员和函数就没有this指针，必须通过类名称来访问

8. tcp连接、断开的详细过程？每个过程的标志都有什么？ 

9. 平时如何调试程序？断点的原理是什么？

     调试断点，依赖于父进程和子进程之间的通信，打断点实际是在被调试的程序中，改变断点附近程序的代码，这个断点使得被调试的程序，暂时停止，然后发送信号给父进程（调试器进程），然后父进程能够得到子进程的变量和状态。达到调试的目的。
         修改断点附近程序的指令地址为0xcc，这个地址的指令就是int 3，含义是，是当前用户态程序发生中断，告诉内核当前程序有断点，那么内核中会向当前进程发送SIGTRAP信号，使当前进程暂停。父进程调用wait函数，等待子进程的运行状态发生改变，这时子进程由于int 3中断，子进程暂停，父进程就可以开始调试子进程的程序了

10. 链表对折

#### 二面

1. http请求的方法

     Get 请求指定的页面信息，并返回实体主体

     HEAD类似于get请求，只不过返回的响应中没有具体的内容，用于获取报文头部

     Post向指定资源提交数据进行处理请求，数据包含在请求体中，post请求可能会导致新的资源的建立和已有资源的修http报文结构

     请求消息一般是请求行、请求头、空行、请求数据四个

     - 请求行：用来说明请求类型，要访问的资源以及所使用的http版本
     - 请求头部：用来说名服务器要附加的信息
     - 空行，请求头部后面的空行是必须的
     - 主体，可以添加任意类型的数据

     响应消息

     - 状态行：协议版本号，状态码，状态消息三个部分组成
     - 消息报头：用来说明一些客户端要使用的一些附加机制 
     - 空行：消息报头后面必须有空行
     - 响应正文，服务器返回给客户端的文本信息

2. 说几个http首部的字段？管线化是什么？怎么保证服务器按顺序返回？

     - 四种首部字段https://www.cnblogs.com/lizhengtan/p/5494089.html
       - 通用首部字段：请求报文和响应报文双方都会使用的
         - Connction ：控制不在代理的的首部字段，管理持久化连接
         - Data: 表明创建http报文的时间和日期
         - Transfer-Encoding:规定了传输报文主体时采用的编码方式
       - 请求首部字段
         - Accept:通知服务端，该用户能处理的媒体类型和相对优先级
         - Accept-language:告知服务器用户代理支持自然语言集以及相对优先级
         - Accept-Encoding:用来告知服务器用户代理支持的内容编码与内容编码的优先级顺序

3. 说下tcp的特点有哪些？详细讲tcp的一些机制？为什么需要这些机制？详细讲tcp报文首部？

     面向连接的字节流可靠传输，他有确认应答机制，超时重传机制，流量控制，拥塞控制，等等，这些机制都是为了可靠传输，

     ![img](https://img-blog.csdn.net/20180324192146298?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzMyOTk4MTUz/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

4. 已知结构体类型和指向某个成员的指针，求结构体起始地址，例如：

   struct A {int a; int b;...;int c;...}；指向结构体变量a中c成员的指针是int *p。求a的地址？

5. 逆时针打印矩阵

     ~~~cpp
     package p4;
      
     /**
      * 逆时针打印矩阵
      * @author Guozhu Zhu
      * @date 2018/7/29
      * @version 1.0
      *
      */
     public class Test02 {
     	
     	public static void main(String[] args) {
     		int[][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
     		int[] res = Solution01(arr, 4, 3);
     		for (int i : res) {
     			System.out.println(i);
     		}
     	}
     	
     	public static int[] Solution01(int[][] arr, int n, int m) {
     		int startX = 0;
     		int startY = 0;
     		int endX = m-1;
     		int endY = n-1;
     		int index = 0;
     		int[] res = new int[n*m];
     		while (startX <= endX && startY <= endY) {
     			// 上---->下
     			if (startY <= endY) {
     				for (int i = startY; i <= endY; i++) {
     					res[index++] = arr[i][startX];
     				}
     			}
     			// 左---->右 (两列以上)
     			if (startX < endX) {
     				for (int i = startX+1; i <= endX; i++) {
     					res[index++] = arr[endY][i];
     				}
     			}
     			// 下---->上(两行两列以上)
     			if (startX < endX && startY < endY) {
     				for (int i = endY-1; i >= startY; i--) {
     					res[index++] = arr[i][endX];
     				}
     			}
     			// 右---->左(三列两行以上)
     			if (startX < endX-1 && startY < endY) {
     				for (int i = endX-1; i >= startX+1; i--) {
     					res[index++] = arr[startY][i];
     				}
     			}
     			startX++;
     			startY++;
     			endX--;
     			endY--;
     		}
     		return res;
     	}
      
     }
     ~~~

     

6. 已知f()函数以概率p输出1，以概率1-P输出0。然后实现g()等概率的输出1和0:

     int g() 

     { 

     } 

     进一步通过刚实现的g()，实现等概率输出0-n的函数int h(int n): 

     int h(int n) 

     { 

     }

7. 实现Linux命令tail -f filename的函数？（需要检查参数和文件类型是否合格）

   int main(int argc, char* argv[])

   {

   }

#### 四面

1. 二叉树的右视角

~~~cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rSVhelp(root,res,0);
        return res;
    }
    void rSVhelp(TreeNode *r,vector<int> &res,int depth){
        if(r==NULL) return;
        if(depth+1>res.size()) res.resize(depth+1);
        res[depth]=r->val;
        rSVhelp(r->left,res,depth+1);
        rSVhelp(r->right,res,depth+1);
    }
};
~~~

