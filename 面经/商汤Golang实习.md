## 商汤Golang实习 

tcp为什么是可靠的运输协议？

1. 面向字节流的
2. 确认应答机制
3. 超时重传机制
4. 拥塞控制
5. 流量控制
6. ip数据包可能会错乱，会进行重排

tcp断开的时候是什么样子的？

1. 第一次挥手服务端主动关闭进入fin_wait1状态进入到finwait2，客户端进入CloseWait状态
2. 客户端发送最后一个lastack,服务端进入Time Wait状态

tcp哪方会处于`TIME_WAIT`状态？

四次挥手中的包中网络中丢失，tcp会怎么处理？

关于丢包问题的博客https://www.jianshu.com/p/69695f332a71

**SeqNum和Ack是以字节数为单位，所以ack的时候，不能跳着确认，只能确认最大的连续收到的包**

TCP重传机制

1. 超时重传机制

   对于12345 ，接受方只收到了12 45,3丢了

   不会ack，死等3，超时重传，这种会导致45即使到了也不发送ack，也可能会导致45重传

   因此两种选择

   - 仅仅重传超时的包3	慢
   - 重传345所有的包     快

2. 拥塞控制中的快速重传控制

   以一种叫**Fast Retransmit**算法，不是以时间驱动，而是以数据驱动，如果，包没有连续到达，就ack最后那个可能被丢了的包，如果发送方连续收到3次相同的ack，就重传

   ![img](https://upload-images.jianshu.io/upload_images/2257417-090e895de71c2153.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/450/format/webp)

有tcp做过一些`CS`的服务模型吗？

三次握手是发生在`accept()`之前还是之后？如果服务端只是调用了`listen()`就进行了三次握手呢？

发生在accept之前，connect请求，只调用了listen不会进行三次握手

我看你写过一个数据库项目，那数据库的原理是什么？

有个`sql`语句，`where`子句怎么优化查询？

编程题：二叉树的叶子节点的最近公共祖先

~~~cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root == p||root == q) return root;
        auto left = lowestCommonAncestor(root->left,p,q);
        auto right = lowestCommonAncestor(root ->right,p,q);
        if(left&&right) return root;
        if(left) return left;
        else return right;
        
    }
};
~~~



项目相关问题

你有什么问题吗？

有什么你了解的，我没问到的？

最近有看什么书吗？

有写过多线程程序吗？如果多个线程修改同一变量呢？

加锁