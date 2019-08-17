### Shopee后台开发面经

链接：

https://www.nowcoder.com/discuss/224176?type=2&order=0&pos=145&page=1

来源：牛客网

一面

 讨论项目（略）

#### 1. 算法题:一堆数怎么排序拼起来能得到一个最大的数

~~~cpp
//剑指offer是找最大的数
class Solution {
   static bool cmp(int &a, int& b ){
        return (to_string(a) + to_string(b)) > (to_string(b) + to_string(a));
    }
public:
    string printMinNumber(vector<int>& nums) {
        // cout << "jjdisd"<<endl;
        string str = "";
        if(nums.size() == 0)
        return str;
        if(nums.size() == 1){
          str = to_string(nums[0]);
         return str;
            
        }
        sort(nums.begin(),nums.end(),cmp);
       
        for(int i = 0; i < nums.size(); i ++){
            str += to_string(nums[i]);
        }
        return str;
    }
};
~~~

#### 2. epoll底层实现

1 int epoll_create(int size);
2 int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
3 int epoll_wait(int epfd, struct epoll_event *events,int maxevents, int timeout);

函数用法不在这里讲解；

首先epoll_create创建一个epoll文件描述符，底层同时创建一个**红黑树**，和一个**就绪链表**；红黑树存储所监控的文件描述符的节点数据，就绪链表存储就绪的文件描述符的节点数据；epoll_ctl将会添加新的描述符，首先判断是红黑树上是否有此文件描述符节点，如果有，则立即返回。如果没有， 则在树干上插入新的节点，并且告知**内核注册回调函数**。当接收到某个文件描述符过来数据时，那么内核将该节点插入到就绪链表里面。epoll_wait将会接收到消息，并且将数据拷贝到用户空间，清空链表。对于LT模式epoll_wait清空就绪链表之后会检查该文件描述符是哪一种模式，**如果为LT模式，且必须该节点确实有事件未处理，那么就会把该节点重新放入到刚刚删除掉的且刚准备好的就绪链表，epoll_wait马上返回。ＥＴ模式不会检查，只会调用一次**

 #### 3. stl set内部实现

红黑树

 #### 4. 红黑树和哈希表比较

**哈希表（Hash table，也叫散列表），是根据键值(Key)而直接进行访问的数据结构。也就是说，它通过把键值映射到表中一个位置来访问记录，以加快查找的速度。这个映射函数叫做散列函数，存放记录的数组叫做散列表**

Red-Black Tree，又称为“红黑树”，它一种特殊的二叉查找树。红黑树的每个节点上都**有存储位表示节点的颜色**，可以是红(Red)或黑(Black)。红黑树的应用比较广泛，主要是用它来存储有序的数据，它的时间复杂度是O(lgn)（**二叉树最大查找次数等于树的深度）**

#### 5. 哈希冲突解决

- 开放地址法
- 

 链表和数组的使用场景

 LRU缓存设计思路

 C++函数参数入栈顺序

 C++地址空间从上到下讲讲

 fork一个子进程，和父进程共享什么

 讲讲多态

 静态链接和动态链接的区别

 进程通信方式

 tcp三次握手流程，为什么三次

 tcp可靠性保证 顺序保证

 tcp每一个字节都返回ack吗

 如果客户端第一个发送的序列号是3，服务端实际先接到的是5，这种情况怎么保证的顺序

 客户端断了，服务端知道吗

 如何优雅关闭连接

 什么是MTU

 客户端服务端tcp建立连接接口函数

 mysql索引类型，底层实现

 b+树的特性 为什么用b+树

 讲讲哈夫曼编码

 亿万个单词TOPK，如果内存装不下呢 

 Redis Zset底层实现 

 跳表查第K大数流程 

 不用中序遍历查二叉搜索树第K大数 

 对于哈希表，预测1分钟之内对它访问多少次 

 用引用计数？你那是测试，不用考虑业务场景，就是推测一下。？？？ 

 哈希表根据键值进行查询时候CPU底层会如何工作，产生什么指令 

 一道嵌套递归的代码，先推导出递归公式，再分析它的复杂度 

 如果让你学一门新语言新技术你会如何去学。