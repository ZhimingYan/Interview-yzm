//
// Created by yzm on 12/14/18.
//
#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <queue>
#include <math.h>
#include <assert.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <limits.h>
#include <stdio.h>
#include <map>
#include <list>
#include <string.h>
using namespace std;

  struct ListNode {
        int val;
        struct ListNode *next;
       ListNode(int x) :
              val(x), next(NULL) {
       }
  };
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;

     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

/**
 *二维数组查找
 * */
     class Solution {
     public:
         bool Find(int target, vector<vector<int> > array) {
             int r = array.size();
             int c = array[0].size();
             int i = r - 1;
             int j = 0;
             while (i >= 0 && j < c) {
                 if (array[i][j] == target)
                     return true;
                 if (array[i][j] > target)
                     i--;
                 else
                     j++;
             }
             return false;
         }
     };

/**
 * 替换空格
 * */
     class Solution1 {
     public:
         void replaceSpace(char *str, int length) {
             if (str == NULL || length < 0)
                 return;
             int spacecnt = 0;
             int i = 0;
             int oldLength = 0;
             while (str[i] != '\0') {
                 oldLength++;
                 if (str[i] == ' ')
                     spacecnt++;
                 i++;
             }
             int newLength = oldLength + 2 * spacecnt;
             if (newLength > length)
                 return;
             int p1 = oldLength;
             int p2 = newLength;
             while (p1 >= 0 && p2 > p1) {
                 if (str[p1] == ' ') {
                     str[p2--] = '0';
                     str[p2--] = '2';
                     str[p2--] = '%';
                 } else {
                     str[p2--] = str[p1];
                 }
                 p1--;
             }
             return;

         }
     };

/**
 * 从尾到头打印链表
 * */
     class Solution2 {
     public:
         vector<int> printListFromTailToHead(ListNode *head) {
             vector<int> res;
             if (head == nullptr)
                 return res;
             ListNode *temp = nullptr;
             ListNode *pre = nullptr;
             while (head != nullptr) {
                 temp = head->next;
                 head->next = pre;
                 pre = head;
                 head = temp;
             }
             while (pre != nullptr) {
                 res.push_back(pre->val);
                 pre = pre->next;
             }
             return res;
         }
     };

/**
 * 重建二叉树
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * */
     class Solution3 {
     public:
         TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
             if (pre.size() == 0 || vin.size() == 0 || pre.size() != vin.size())
                 return nullptr;
             return construct(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);

         }

     private:
         TreeNode *construct(vector<int> pre, int ps, int pe, vector<int> vin, int vs, int ve) {
             if (ps > pe)
                 return nullptr;
             int value = pre[ps];
             int index = vs;
             while (index <= ve && value != vin[index]) {
                 index++;
             }
             if (index > ve) {
                 cout << "Invalid Input";
                 return nullptr;
             }
             TreeNode *node = new TreeNode(value);
             node->left = construct(pre, ps + 1, ps + index - vs, vin, vs, index - 1);
             node->right = construct(pre, ps + index - vs + 1, pe, vin, index + 1, ve);
             return node;
         }

     };

/**
 * 两个栈实现一个队列
 * */
     class Solution4 {
     public:
         void push(int node) {
             stack1.push(node);
         }

         int pop() {
             if (stack2.empty()) {
                 while (stack1.size() > 0) {
                     int data = stack1.top();
                     stack1.pop();
                     stack2.push(data);
                 }
             }
             int a = stack2.top();
             stack2.pop();
             return a;
         }

     private:
         stack<int> stack1;
         stack<int> stack2;
     };

/**
 * 旋转数组最小值
 * */
     class Solution6 {
     public:
         int minNumberInRotateArray(vector<int> rotateArray) {
             if (rotateArray.size() == 0)
                 return 0;
             for (int i = 0; i < rotateArray.size() - 1; i++) {
                 if (rotateArray[i] > rotateArray[i + 1])
                     return rotateArray[i + 1];
             }
             return rotateArray[0];
         }
     };
 };
/**
 * 费那波数列
 * */
class Solution7 {
public:
    int Fibonacci(int n) {
        vector<int>memo(n+1,-1);
        memo[0]=0;
        memo[1]=1;
        for(int i = 2; i <=n; i++ ){
            memo[i] = memo[i-1]+memo[i-2];
        }
        return memo[n];

    }
};
/**
 * 跳台阶
 * */
class Solution8 {
public:
    int jumpFloor(int number) {
        int res = 0;
        memo = vector<int>(number+1,0);
        res = calWays(number);
        return res;
    }
private:
    vector<int> memo;
    int calWays(int n){
        if( n == 0)
            return 1;
        if( n == 1)
            return 1;
        if(memo[n] == 0)
            memo[n] = calWays(n-1)+calWays(n-2);
        return memo[n];

    }
};

/**
 * 变态跳台阶
 * */
class Solution9 {
public:
    int jumpFloorII(int number) {
        if(number==0)
            return number;
        int total=1;
        for(int i=1;i<number;i++)
            total*=2;
        return total;
    }
};

/**
 * 矩形覆盖
 * */
class Solution10 {
public:
    int rectCover(int number) {
        if(number <= 0){
            return 0;
        }
        //  else if(number ==1|| number == 2){
        //     return number;
        //  }
        // return (rectCover(number-1)+rectCover(number-2));

        vector<int>memo(number+1,0);
        //if (number == 1)
        //return 1;
        // if (number == 2)
        //return 2;

        //if(memo[number] == 0)
        // memo[number] = rectCover(number-1)+rectCover(number-2);
        //return memo[number];
        memo[1]=1;
        memo[2]=2;
        for(int i = 3; i <=number; i++ ){
            memo[i] = memo[i-1]+memo[i-2];
        }
        return memo[number];
    }
};
/**
 * 二进制中1的个数
 * */
class Solution11 {
public:
    int  NumberOf1(int n) {
        int count = 0;
        while(n!= 0){
            count++;
            n = n & (n - 1);
        }
        return count;
    }

};

/**
 * 浮点数的整数次方
 * */
class Solution12 {
public:
    double Power(double base, int exponent) {
        long long p = abs( (long long) exponent);
        double r = 1.0;
        while (p) {
            if (p & 1)
                r *= base;
            base *= base;
            p >>= 1;
        }
        return ( exponent > 0 ) ? r : 1/r;
    }
};

/**
 * 调整数组顺序使奇数位于偶数前面
 * */
 //这个是一系列问题，需要吧判读条件改变一下进行代码的复用
class Solution13 {
public:
    void reOrderArray(vector<int> &array) {
        //时间换空间的解法，面试过程中会遇到
        for (int i = 0; i < array.size();i++)
        {
            for (int j = array.size() - 1; j>i;j--)
            {
                if (array[j] % 2 == 1 && array[j - 1]%2 == 0) //前偶后奇交换、、此处可以进行修改
                {
                    swap(array[j], array[j-1]);
                }
            }
        }
    }
};
/**
 * 输出链表中的倒数第k个节点
 * */
//class Solution {
//public:
//    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//        ListNode* preNode = pListHead;
//        ListNode* nextNode = pListHead;
//        for( int i =0; i!= k; i++)
//            if(!nextNode)
//                return nullptr;
//        else
//        nextNode = nextNode->next;
//        while(preNode != nullptr)
//        {
//            preNode = preNode->next;
//            nextNode = nextNode->next;
//        }
//        return preNode;
//    }
//};
class Solution14 {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(!pListHead||k==0)
            return nullptr;//代码的鲁棒性
        auto p1=pListHead;
        for(int i=0;i!=k;++i)
            if(!p1)return nullptr;//代码的鲁棒性
            else
                p1=p1->next;
        while(p1){
            p1=p1->next;
            pListHead=pListHead->next;
        }
        return pListHead;

    }
};

/**
 * 翻转链表
 * */
class Solution15 {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead||!pHead->next)//考察代码的鲁棒性
            return pHead;
        ListNode* temp = nullptr;
        ListNode* pre = nullptr;
        while(pHead)
        {
            temp = pHead -> next;
            pHead->next = pre;
            pre = pHead;
            pHead = temp;

        }

        return pre;
    }
};

/**
 * 合并两个排序的链表
 * */
class Solution16 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        //ListNode* dummmyHead = new ListNode(0);
        ListNode* dummy = new ListNode(0);
        while(pHead1||pHead2){
            if(pHead1 == nullptr)
            {
                dummy->next = new ListNode(pHead2->val);
                pHead2 = pHead2->next;
            }
            else if(pHead2 == nullptr)
            {
                dummy->next = new ListNode(pHead1->val);
                pHead1 = pHead1->next;
            }
            else if(pHead1->val<=pHead2->val)
            {
                dummy->next = new ListNode(pHead1->val);
                pHead1 = pHead1->next;
            } else {
                dummy->next = new ListNode(pHead2->val);
                pHead2 = pHead2->next;
            }
            dummy = dummy->next;
        }
        return dummy->next;
    }
    //还可以用归并排序的解法
    ListNode* Merge2(ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1)
            return pHead2;
        if(!pHead2)
            return pHead1;
        ListNode* pMergeNode = nullptr;
        if(pHead1->val < pHead2 ->val){
            pMergeNode = pHead1;
            pMergeNode->next = Merge2(pHead1->next,pHead2);
        } else{
            pMergeNode = pHead2;
            pMergeNode->next = Merge2(pHead1,pHead2->next);
        }
        return pMergeNode;
    }
};


/**
 * 树的子结构
 * */
 //关于该问题的解决思路就是先找到跟节点相同的值就相等
class Solution17 {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot1)
            return false;
        if(!pRoot2)
            return false;
        return ( dfs(pRoot1,pRoot2)) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
private:
    bool dfs(TreeNode * r1, TreeNode * r2){
        if(!r2)
            return true;
        if(!r1)
            return false;
        if(r1->val != r2->val)
            return false;
        return dfs(r1->left, r2->left) && dfs(r1->right, r2->right);
    }

};

/**
 * 镜像二叉树
 * */
class Solution18 {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == nullptr)
            return;
        //swap(pRoot->right,pRoot->left);
        TreeNode *pTmp;
        pTmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pTmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);

    }
};
/**
 * 打印旋转矩阵
 *
 * */
class Solution19 {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int r = matrix.size()-1;
        int c = matrix[0].size()-1;
        int i = 0;
        int j = 0;
        while (r>=0&&c>=0){
            for(int m = j; m < c-1;m++)
                res.push_back(matrix[i][m]);
            for(int n = i; n < r-1;n++)
                res.push_back(matrix[n][j]);
            for(int l = c-1; l >0;l--)
                res.push_back(matrix[i+r][l]);
            for(int q = r-1; q > 0;q--)
                res.push_back(matrix[q][j+c]);
            i++;
            j++;
            r=r-2;
            c= c-2;
        }
        return  res;
    }
    vector<int> printMatrix2(vector<vector<int> > matrix) {
        vector<int>res;
        res.clear();
        int row=matrix.size();//行数
        int collor=matrix[0].size();//列数
        //计算打印的圈数
        int circle=((row<collor?row:collor)-1)/2+1;//圈数
        for(int i=0;i<circle;i++){
            //从左向右打印
            for(int j=i;j<collor-i;j++)
                res.push_back(matrix[i][j]);
            //从上往下的每一列数据
            for(int k=i+1;k<row-i;k++)
                res.push_back(matrix[k][collor-1-i]);
            //判断是否会重复打印(从右向左的每行数据)
            for(int m=collor-i-2;(m>=i)&&(row-i-1!=i);m--)
                res.push_back(matrix[row-i-1][m]);
            //判断是否会重复打印(从下往上的每一列数据)
            for(int n=row-i-2;(n>i)&&(collor-i-1!=i);n--)
                res.push_back(matrix[n][i]);}
        return res;
    }
    vector<int> printMatrix3(vector<vector<int>> matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> result;
        if(row==0||col==0)
            return result;
        int left=0,right=col-1,top=0,btm=row-1;
        while(left<=right&&top<=btm)
        {
            for(int i=left;i<=right;i++)
                result.push_back(matrix[top][i]);
            if(top<btm)
                for(int i=top+1;i<=btm;i++)
                    result.push_back(matrix[i][right]);
            if(top<btm&&left<right)
                for(int i=right-1;i>=left;i--)
                    result.push_back(matrix[btm][i]);
            if(top+1<btm&&left<right)
                for(int i=btm-1;i>=top+1;i--)
                    result.push_back(matrix[i][left]);
            left++;right--;top++;btm--;
        }
        return result;
    }
};
/**
 * 包含min函数的最小栈
 * */
class Solution20 {
public:
    void push(int value) {
        if(stack1.empty())
        {
            stack1.push(value);
            stack2.push(value);
        }else if(value <= min()){
          stack2.push(value);
          stack1.push(value);
        } else
            stack1.push(value);
    }
    void pop() {
        if(!stack1.empty()&&stack1.top()!=stack2.top())
        {stack1.pop();
       }
        else if(!stack1.empty()&&stack1.top()==stack2.top())
        {
            stack1.pop();
            stack2.pop();
        }
        else{
            cout<<"No numbers"<<endl;
            exit(0);
        };
    }
    int top() {
        if(!stack1.empty()&&stack1.top()!=stack2.top())
        {
            return  stack1.top();
        }
        else if(!stack1.empty()&&stack1.top()==stack2.top())
        {
            int res = stack1.top();
            stack1.pop();
            stack2.pop();
            return res;
        }
        else{
            cout<<"No numbers"<<endl;
            return -1;
        };

    }
    int min() {
        return stack2.top();

    }
private:
    stack<int> stack1;
    stack<int> stack2;
};
//优质解法
class Solution {
public:
    void push(int value) {
        StackInt.push(value);
        if(StackMin.empty())
            StackMin.push(value);
        else if(StackMin.top()<value)
            StackMin.push(StackMin.top());
        else
            StackMin.push(value);
    }
    void pop() {
        if(!StackInt.empty())
        {
            StackInt.pop();
            StackMin.pop();
        }
    }
    int top() {
        return StackInt.top();
    }
    int min() {
        return StackMin.top();
    }
private:
    stack<int> StackInt;
    stack<int> StackMin;
};

/**
 * 栈的压入弹出序列
 * */
//【思路】借用一个辅助的栈，遍历压栈顺序，先讲第一个放入栈中，这里是1，然后判断栈顶元素是不是出栈顺序的第一个元素，这里是4，很显然1≠4，所以我们继续压栈，直到相等以后开始出栈，出栈一个元素，则将出栈顺序向后移动一位，直到不相等，这样循环等压栈顺序遍历完成，如果辅助栈还不为空，说明弹出序列不是该栈的弹出顺序。
//举例：
//入栈1,2,3,4,5
//出栈4,5,3,2,1
//首先1入辅助栈，此时栈顶1≠4，继续入栈2
//        此时栈顶2≠4，继续入栈3
//        此时栈顶3≠4，继续入栈4
//        此时栈顶4＝4，出栈4，弹出序列向后一位，此时为5，,辅助栈里面是1,2,3
//此时栈顶3≠5，继续入栈5
//        此时栈顶5=5，出栈5,弹出序列向后一位，此时为3，,辅助栈里面是1,2,3
class Solution21 {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        assert(pushV.size() != popV.size() && pushV.size() > 0);
        stack<int> s;
        //用于标志弹出序列的位置
        int popIndex = 0;
        for (int i = 0; i < pushV.size(); i++) {
            s.push(pushV[i]);
            //如果栈不为空，且栈顶元素等于弹出序列
            while (!s.empty() && s.top() == popV[popIndex]) {
                //出栈
                s.pop();
                //弹出序列向后一位
                popIndex++;
            }
        }
        return s.empty();
    }
};
/**
 * 二叉树的层序遍历
 * */
class Solution22 {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int>res;
        if(root == nullptr)
            return res;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);

            // 接着遍历
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        return  res;

    }
};

/**
 * 二叉搜索树的后续遍历序列
 * */
class Solution23 {
public:
    bool VerifySquenceOfBST1(vector<int> sequence) {//超过了使用的内存
        if(sequence.size()==0)
            return false;
        int root = sequence[sequence.size()-1];
        vector<int>left;
        vector<int>right;
        int i = 0;
        while(i< sequence.size() ){
            if(sequence[i]<root)
            left.push_back(sequence[i++]);
            else if(sequence[i]==root)
                return false;
            else
                break;
        }
        int j =i;
        while(j<sequence.size()){
            if(sequence[j] < root)
                return false;
            else
                right.push_back(sequence[j++]);
        }
        bool l = true;
        bool r = true;
        if( i > 0) {
            l = VerifySquenceOfBST(left);
        }

        if(j < sequence.size()-1) {
            r = VerifySquenceOfBST(right);
        }
        return l&&r;
    }
    //非递归
//非递归也是一个基于递归的思想：
//左子树一定比右子树小，因此去掉根后，数字分为left，right两部分，right部分的
//最后一个数字是右子树的根他也比左子树所有值大，因此我们可以每次只看有子树是否符合条件
//即可，即使到达了左子树左子树也可以看出由左右子树组成的树还想右子树那样处理

//对于左子树回到了原问题，对于右子树，左子树的所有值都比右子树的根小可以暂时把他看出右子树的左子树
//只需看看右子树的右子树是否符合要求即可
    bool VerifySquenceOfBST2(vector<int> sequence) {
        int size = sequence.size();
        if(0==size)return false;

        int i = 0;
        while(--size)
        {
            while(sequence[i++]<sequence[size]);
            while(sequence[i++]>sequence[size]);

            if(i<size)return false;
            i=0;
        }
        return true;
    }
    //递归

    bool judge(vector<int>& a, int l, int r){
        if(l >= r) return true;
        int i = r;
        while(i > l && a[i - 1] > a[r]) --i;
        for(int j = i - 1; j >= l; --j) if(a[j] > a[r]) return false;
        return judge(a, l, i - 1) && (judge(a, i, r - 1));
    }
public:
    bool VerifySquenceOfBST(vector<int> a) {
        if(!a.size()) return false;
        return judge(a, 0, a.size() - 1);
    }
};
/**
 * 二叉树中和为1某一值的路劲
 * */
class Solution24 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        vector<vector<int>> res_tmp = _pathSum(root, sum);
        vector<vector<int>> res= res_tmp;

        // 形式整理输出，本来是倒序的
        for (int i = 0; i < res_tmp.size(); i++) {
            int len = res_tmp[i].size();
            for (int j = 0; j < len; j++) {
                res[i][j] = res_tmp[i][len - 1 - j];
            }
        }

        return res;
    }

    static vector<vector<int>> _pathSum(TreeNode* root, int sum) {

        if (root == NULL)
            return vector<vector<int>>();

        vector<vector<int>> res;

        // 找到了符合题意的叶子结点，意味着生成了一条路径
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            vector<int> path;
            path.push_back(root->val);
            res.push_back(path);
        }

        // 当前节点的左子树的正确路径
        vector<vector<int>> leftPath = _pathSum(root->left, sum - root->val);
        for (int i = 0; i < leftPath.size(); i++) {
            leftPath[i].push_back(root->val);
        }
        // 当前节点的右子树的正确路径
        vector<vector<int>> rightPath = _pathSum(root->right, sum - root->val);
        for (int i = 0; i < rightPath.size(); i++) {
            rightPath[i].push_back(root->val);
        }
        // 整理成当前节点正确路径数的形式
        for (int i = 0; i < leftPath.size(); i++) {
            res.push_back(leftPath[i]);
        }
        for (int i = 0; i < rightPath.size(); i++) {
            res.push_back(rightPath[i]);
        }

        return res;
    }

};
/**
 * 别人的代码，非常简洁
 * */
class SolutionFind {
    vector<vector<int> >allRes;
    vector<int> tmp;
    void dfsFind(TreeNode * node , int left){
        tmp.push_back(node->val);
        if(left-node->val == 0 && !node->left && !node->right)
            allRes.push_back(tmp);
        else {
            if(node->left) dfsFind(node->left, left-node->val);
            if(node->right) dfsFind(node->right, left-node->val);
        }
        tmp.pop_back();
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root) dfsFind(root, expectNumber);
        return allRes;
    }
};

/**
 * 复杂链表的复制//之后在详细解析
 * */

struct RandomListNode {
   int label;
   struct RandomListNode *next, *random;
   RandomListNode(int x) :
           label(x), next(NULL), random(NULL) {
   }
};

class Solution25 {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
            return nullptr;
        RandomListNode* cur = pHead;
        unordered_map<RandomListNode*,RandomListNode*>mymap;
        while (cur){
            mymap[cur]= new RandomListNode(cur->label);
            //mymap.insert(cur,new RandomListNode(cur->label));
            pHead = cur->next;

        }

        while (cur){
            mymap[cur]->next = mymap[cur->next];
            mymap[cur]->random = mymap[cur->random];
            cur = cur->next;

        }

        return mymap[pHead];
    }
};

/**
 * 二叉搜索树与双向链表
 * */


class Solution26 {
public:

        TreeNode* Convert(TreeNode* pRootOfTree)
        {
            if(pRootOfTree == nullptr) return nullptr;
            TreeNode* pre = nullptr;

            convertHelper(pRootOfTree, pre);

            TreeNode* res = pRootOfTree;
            while(res ->left)
                res = res ->left;
            return res;
        }

        void convertHelper(TreeNode* cur, TreeNode*& pre)
        {
            if(cur == nullptr) return;

            convertHelper(cur ->left, pre);

            cur ->left = pre;//前驱节点
            if(pre) pre ->right = cur;//如果前驱节点不为空（即不是头节点），则将当前节点作为前驱节点的后区节点
            pre = cur;//将当前节点保存为下一轮前驱节点

            convertHelper(cur ->right, pre);



        }


};
/**
 * 字符串的顺序排列
 * 按照字典顺序打印出所有字符的所有排列
 * */
class Solution27 {

    void PermutationHelp(vector<string> &ans, int k, string str) //遍历第k位的所有可能
    {
        if(k == str.size() - 1)
            ans.push_back(str);
        unordered_set<char> us;  //记录出现过的字符
        sort(str.begin() + k, str.end());  //保证按字典序输出
        for(int i = k; i < str.size(); i++)
        {
            if(us.find(str[i]) == us.end()) //只和没交换过的换
            {
                us.insert(str[i]);
                swap(str[i], str[k]);
                PermutationHelp(ans, k + 1, str);
                swap(str[i], str[k]);  //复位
            }
        }
    }

public:
    vector<string> Permutation(string str) {
        vector<string> ans;
        PermutationHelp(ans, 0, str);
        return ans;
    }

};

/**
 * 数组中出现次数超过一半的数字
 * */
class Solution28 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int mid = numbers.size()>>1;
        int start = 0;
        int end = numbers.size() -1;
       int index =  Partition(numbers,0,numbers.size()-1);
       while (index != mid){
           if(index >mid){
               end =  index - 1;
               index = Partition(numbers,start,end);
           } else{
               start = index + 1;
               index = Partition(numbers,start,end);
           }
       }
       int res = numbers[mid];
        return res;

    }

private:
    int Partition(vector<int> &arr,int start, int end)
    {
        if(arr.size() == 0)
            return 0;
        int less = start-1;
        int more = end;
        int cur = start;
        while(less <= more){
            if(arr[cur] <= arr[end]){
                swap(arr[cur++],arr[++less]);
            } else
                swap(arr[cur++],arr[more--]);
        }
        swap(arr[more], arr[cur]);
        return less;

    }
public:
    //优质解法
    int MoreThanHalfNum_Solution2(vector<int> numbers) {
        int n = numbers.size();
        if (n == 0) return 0;

        int num = numbers[0], count = 1;
        for (int i = 1; i < n; i++) {
            if (numbers[i] == num) count++;
            else count--;
            if (count == 0) {
                num = numbers[i];
                count = 1;
            }
        }
        // Verifying
        count = 0;
        for (int i = 0; i < n; i++) {
            if (numbers[i] == num) count++;
        }
        if (count * 2 > n) return num;
        return 0;
    }
    //快排思想
    int MoreThanHalfNum_Solution3(vector<int> numbers)
    {
        // 因为用到了sort，时间复杂度O(NlogN)，并非最优
        if(numbers.empty()) return 0;

        sort(numbers.begin(),numbers.end()); // 排序，取数组中间那个数
        int middle = numbers[numbers.size()/2];

        int count=0; // 出现次数
        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i]==middle) ++count;
        }

        return (count>numbers.size()/2) ? middle :  0;
    }
    //剑指offer的解法
    int MoreThanHalfNum_Solution4(vector<int> numbers)
    {
        if(numbers.empty()) return 0;

        // 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
        int result = numbers[0];
        int times = 1; // 次数

        for(int i=1;i<numbers.size();++i)
        {
            if(times == 0)
            {
                // 更新result的值为当前元素，并置次数为1
                result = numbers[i];
                times = 1;
            }
            else if(numbers[i] == result)
            {
                ++times; // 相同则加1
            }
            else
            {
                --times; // 不同则减1
            }
        }

        // 判断result是否符合条件，即出现次数大于数组长度的一半
        times = 0;
        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i] == result) ++times;
        }

        return (times > numbers.size()/2) ? result : 0;
    }
};

/**
 * 最小的k个数
 * */
 //如果先进行排序，则算法复杂度Q（NlgN）
//基于快排思想
 class Solution29 {
 public:
     vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
         // 可以用快排思维查找第k个元素的值
         int r = input.size()-1;
         // 外部第k大和内部数组索引之间需要自己维护
         int ret = quickSearch(input, 0, r, k-1);
         srand(time(NULL));
         vector<int>output(input.begin(),input.begin()+k);
         //output.assign;
         return output;

     }

 private:
     // 子函数：用于寻找[l,r]之间起始数值在区间内的正确排序索引
     int _quickSearch(vector<int>& nums, int l, int r, int k) {

         // 随机取[l,r]之间的随机数
         int t = rand() % (r - l + 1) + l;
         swap(nums[l], nums[t]);

         // 最终[l,j-1]内的数值都>v
         int v = nums[l];
         int j = l;
         for (int i = l + 1; i <= r; i++) {
             if (nums[i] > v) {
                 swap(nums[++j], nums[i]);
             }
         }
         swap(nums[l], nums[j]);

         return j;
     }  // 返回每一次快排的起始随机标志的索引
     int quickSearch(vector<int>& nums, int l, int r, int k) {

         int pivot = _quickSearch(nums, l, r, k);
         if (pivot == k)
             return pivot;
         else if (k < pivot)
             return quickSearch(nums, 0, pivot - 1, k);
         else
             return quickSearch(nums, pivot + 1, r, k);
     }
 public:
     //最大堆的方法  在牛客上调试失败，超出时间限制
     vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
         int len=input.size();
         if(len<=0||k>len) return vector<int>();

         vector<int> res(input.begin(),input.begin()+k);
         //建堆
         make_heap(res.begin(),res.end());

         for(int i=k;i<len;i++)
         {
             if(input[i]<res[0])
             {
                 //先pop,然后在容器中删除
                 pop_heap(res.begin(),res.end());
                 res.pop_back();
                 //先在容器中加入，再push
                 res.push_back(input[i]);
                 push_heap(res.begin(),res.end());
             }
         }
         //使其从小到大输出
         sort_heap(res.begin(),res.end());

         return res;

     }
     //红黑树的 方法
     vector<int> GetLeastNumbers_Solution3(vector<int> input, int k) {
         int len=input.size();
         if(len<=0||k>len) return vector<int>();

         //仿函数中的greater<T>模板，从大到小排序
         multiset<int, greater<int> > leastNums;
         vector<int>::iterator vec_it=input.begin();
         for(;vec_it!=input.end();vec_it++)
         {
             //将前k个元素插入集合
             if(leastNums.size()<k)
                 leastNums.insert(*vec_it);
             else
             {
                 //第一个元素是最大值
                 multiset<int, greater<int> >::iterator greatest_it=leastNums.begin();
                 //如果后续元素<第一个元素，删除第一个，加入当前元素
                 if(*vec_it<*(leastNums.begin()))
                 {
                     leastNums.erase(greatest_it);
                     leastNums.insert(*vec_it);
                 }
             }
         }

         return vector<int>(leastNums.begin(),leastNums.end());
     }

 };


 /**
  * 连续子数组的最大和
  *
  * */
 class Solution30 {
 public:
     //普通方法
     int FindGreatestSumOfSubArray(vector<int> array) {
         if(array.size() <= 0 ){
             bool _IvalidInput = true;
             return 0;
         }

         bool _IvalidInput = false;
         int curSum = 0;
         int sum = INT_MIN;
         for( int i = 0; i < array.size(); i++){
             if(curSum <= 0)//说明当前值不是特别的大
                 curSum = array[i];
             else
                 curSum += array[i];
             sum = max(sum,curSum);
         }
         return sum;
     }
     //动态规划的方法
     int FindGreatestSumOfSubArray2(vector<int> array) {
         int cursum = array[0];
         int sum = array[0];
         for (int i = 1; i < array.size(); i++){
            cursum = max(cursum+array[i],array[i]);//当前最大值的两种情况，要么自己，要么是之前最大值加上自己
            sum = max(cursum,sum);

         }
         return sum;


     }
 };

 /**
  * 整数中１出现的次数
  *
  * */
 class Solution31 {
     int numof1(int n){
         int num=0;
         while(n){
             if(n%10==1)
                 num++;
             n/=10;
         }
         return num;
     }
 public:
     int NumberOf1Between1AndN_Solution(int n)
     {
         //方法１　直接求余数
         int num=0;
         for(int i=1;i<=n;i++){
             num+=numof1(i);
         }
         return num;


     }
     //方法2　找规律
 public:
     int NumberOf1Between1AndN_Solution2(int n) {
         int count = 0;//1的个数
         int i = 1;//当前位
         int current = 0,after = 0,before = 0;
         while((n/i)!= 0){
             current = (n/i)%10; //高位数字
             before = n/(i*10); //当前位数字
             after = n-(n/i)*i; //低位数字
             //如果为0,出现1的次数由高位决定,等于高位数字 * 当前位数
             if (current == 0)
                 count += before*i;
                 //如果为1,出现1的次数由高位和低位决定,高位*当前位+低位+1
             else if(current == 1)
                 count += before * i + after + 1;
                 //如果大于1,出现1的次数由高位决定,//（高位数字+1）* 当前位数
             else{
                 count += (before + 1) * i;
             }
             //前移一位
             i = i*10;
         }
         return count;
     }
 };

 /**
  * 把数组排成最小的数
  * */

 class Solution33 {
 public:
     //定制排序规则
     string PrintMinNumber(vector<int> numbers) {
         int len = numbers.size();
         if(len == 0) return "";
         //基于比较器的相关解法
         sort(numbers.begin(), numbers.end(), cmp);
         string res;
         for(int i = 0; i < len; i++){
             res += to_string(numbers[i]);
         }
         return res;
     }
     //关于static的一些知识
     //作者：军仔007
     //链接：https://www.nowcoder.com/questionTerminal/8fecd3f8ba334add803bf2a06af1b993
     //来源：牛客网
     //
     //sort中的比较函数compare要声明为静态成员函数或全局函数，不能作为普通成员函数，否则会报错。
     //因为：非静态成员函数是依赖于具体对象的，而std::sort这类函数是全局的，因此无法再sort中调用非静态成员函数。
     // 静态成员函数或者全局函数是不依赖于具体对象的, 可以独立访问，无须创建任何对象实例就可以访问。
     // 同时静态成员函数不可以调用类的非静态成员。
     static bool cmp(int a, int b){
         string A = to_string(a) + to_string(b);
         string B = to_string(b) + to_string(a);
         return A < B;
     }

    //lamda 表达式
 public:
     string PrintMinNumber2(vector<int> numbers) {
         sort(numbers.begin(),numbers.end(),[](const int& a,const int& b){
             return to_string(a)+to_string(b)<to_string(b)+to_string(a);});
         string res;
         for (auto c:numbers)
             res+=to_string(c);
         return res;
     }
     //全排列方法，使用回溯法
 };

 /**
  * 丑数
  * 把只包含质因子2、3和5的数称作丑数（Ugly Number）
  * */
 class Solution34 {
 public:
     int GetUglyNumber_Solution(int index) {
         if (index < 7)return index;
         vector<int> res(index);
         res[0] = 1;
         int t2 = 0, t3 = 0, t5 = 0, i;
         for (i = 1; i < index; ++i)
         {
             res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
             if (res[i] == res[t2] * 2)t2++;
             if (res[i] == res[t3] * 3)t3++;
             if (res[i] == res[t5] * 5)t5++;
         }
         return res[index - 1];
     }

     int GetUglyNumber_Solution2(int index) {
         // 0-6的丑数分别为0-6
         if(index < 7) return index;
         //p2，p3，p5分别为三个队列的指针，newNum为从队列头选出来的最小数
         int p2 = 0, p3 = 0, p5 = 0, newNum = 1;
         vector<int> arr;
         arr.push_back(newNum);
         while(arr.size() < index) {
             //选出三个队列头最小的数
             newNum = min(arr[p2] * 2, min(arr[p3] * 3, arr[p5] * 5));
             //这三个if有可能进入一个或者多个，进入多个是三个队列头最小的数有多个的情况
             if(arr[p2] * 2 == newNum) p2++;
             if(arr[p3] * 3 == newNum) p3++;
             if(arr[p5] * 5 == newNum) p5++;
             arr.push_back(newNum);
         }
         return newNum;
     }
 };

 /**
  * 第一个只出现一次的字符
  * */
 class Solution35 {
 public:
     int FirstNotRepeatingChar(string str) {

         map<char,int>mymap;
         for( int i = 0; i < str.size();i++)
             mymap[str[i]]++;

         for(int i = 0 ; i < str.size();i++)//i已经加了1故不需要再次加1
             if(mymap[str[i]] == 1 )
                 return i;
         return -1;


     }
 };

 /**
  * 数组中的逆序对
  * 代码太长了，暂时不做
  * */
 class Solution36 {
 public:
     int InversePairs(vector<int> data) {

     }
 };

 /**
  * 两个链表的第一个公共结点
  * 输入两个链表，找出他们的第一个公共结点
  * */

class Solution37 {
public:
    //我这样做的错误之处是没有体现相交特性，如果有个结点的值等于相交的结点的值就会出现问题，应该将结点地址为键值，但是也编译通不过
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {

        unordered_set<ListNode> myset;
        while (pHead1){
            myset.insert(pHead1);
            pHead1 = pHead1->next;
        }
        while (pHead2){
            if(myset.find(pHead2)!=myset.end())
                return pHead2;
            pHead2 = pHead2->next;
        }
        return nullptr;

    }

    //最短的版本
       ListNode* FindFirstCommonNode2( ListNode *pHead1, ListNode *pHead2) {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1!=p2){
            p1 = (p1==NULL ? pHead2 : p1->next);
            p2 = (p2==NULL ? pHead1 : p2->next);
        }
        return p1;
    }
    //Y型相交链表的求解可以从尾部出发，将利用栈结构
};

/**
 *数字在排序数组中出现的次数
 * */

class Solution38 {
public:
    //第一个类似于计数排序的方法，此方法相对来说不是最优解

    //利用STL中的函数
    int GetNumberOfK(vector<int> data ,int k) {
        auto resultPair = equal_range(data.begin(), data.end(),k);
        return resultPair.second - resultPair.first;
    }

    //比较好的解题思路
    //因为data中都是整数，所以可以稍微变一下，不是搜索k的两个位置，而是搜索k-0.5和k+0.5
    //这两个数应该插入的位置，然后相减即可，该时间复杂度也是最低的
    int GetNumberOfK2(vector<int> data ,int k) {
        return biSearch(data, k+0.5) - biSearch(data, k-0.5) ;
    }
private:
    int biSearch(const vector<int> & data, double num){
        int s = 0, e = data.size()-1;
        while(s <= e){
            int mid = (e - s)/2 + s;
            if(data[mid] < num)
                s = mid + 1;
            else if(data[mid] > num)
                e = mid - 1;
        }
        return s;
    }

    //剑值offer上的题解，时间复杂度最低
    int GetNumberOfK3(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        int number = 0;
        int first = GetFirstIndex(data,k,0,data.size()-1);
        int last = GetLastIndex(data,k,0,data.size()-1);
        if(first>-1 && last>-1)
            number = last - first +1;
        return number;

    }
    int GetFirstIndex(vector<int> &data,int k,int start,int end){
        if(start > end)
            return -1;
        int mid = start+(end-start)/2;
        if(data[mid] == k){
            if((mid == start) || (data[mid-1] != k))
                return mid;
            else
                end = mid-1;
        }
        else{
            if(data[mid] > k)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return GetFirstIndex(data,k,start,end);
    }
    int GetLastIndex(vector<int> &data,int k,int start,int end){
        if(start > end)
            return -1;
        int mid = start+(end-start)/2;
        if(data[mid]==k){
            if((mid == end) || (data[mid+1] != k))
                return mid;
            else
                start = mid +1;
        }
        else{
            if(data[mid]>k)
                end = mid-1;
            else
                start = mid+1;
        }
        return GetLastIndex(data,k,start,end);
    }
};
/**
 * 二叉树的深度
 * */

class Solution39 {
public:
    //使用该方法造成了超过限制的内存。为什么
    int TreeDepth(TreeNode* pRoot)
    {
        int level = 0;
        if(!pRoot)
            return 0;
        queue<pair<TreeNode*,int>>myqueue;
        myqueue.push(make_pair(pRoot,0));
        while(!myqueue.empty()){
            int level = myqueue.front().second;
            myqueue.pop();
            if(pRoot->left)
                 myqueue.push(make_pair(pRoot->left,level+1));
            if(pRoot->right)
              myqueue.push(make_pair(pRoot->right,level+1));
        }
        return level;


    }

    //二叉树的最大深度，等等于左字数的最大深度，等于右字数的最大深度加1
    int TreeDepth2(TreeNode* pRoot){
    if (pRoot == NULL)
    return 0;

    return max(TreeDepth2(pRoot->left), TreeDepth2(pRoot->right)) + 1;}
};
/**
 * 判断一个数是否为平衡二叉树
 * */
 //平衡二叉树，如果每个节点的高度差不超过1

class Solution40 {
public:
    //此方法虽然简单，一个节点会遍历多次，不是特别的好
    bool IsBalanced_Solution(TreeNode* pRoot) {
       if(!pRoot)
           return true;
       int left = TreeDepth2(pRoot->left);
       int right = TreeDepth2(pRoot->right);
       int dff = abs(left-right);
       if( dff > 1)
           return  false;
        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);


    }

private:
    int TreeDepth2(TreeNode* pRoot){
        if (pRoot == NULL)
            return 0;

        return max(TreeDepth2(pRoot->left), TreeDepth2(pRoot->right)) + 1;}

public:
    //后续遍历二叉树，遍历过程中求字数高度，判断是否平衡.剑指offer的方法
    bool IsBalanced(TreeNode *root, int & dep){
        if(root == NULL){
            return true;
        }
        int left = 0;
        int right = 0;
        if(IsBalanced(root->left,left) && IsBalanced(root->right, right)){
            int dif = left - right;
            if(dif<-1 || dif >1)
                return false;
            dep = (left > right ? left : right) + 1;
            return true;
        }
        return false;
    }
    bool IsBalanced_Solution2(TreeNode* pRoot) {
        int dep = 0;
        return IsBalanced(pRoot, dep);
    }
};

/**
 * 数组中只出现一次的数字
 * 进行异或运算太难了，以后在进行解析
 * */
class Solution41 {
public:
    //方法1 进行异或运算
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2)
            return;

        int resultExclusiveOR = 0;
        for(int i = 0; i < data.size(); i++){
            resultExclusiveOR ^= data[i];
        }

        unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

        *num1 = *num2 = 0;
        for(int j = 0; j < data.size(); j++){
            if(IsBit1(data[j], indexOf1))
                *num1 ^= data[j];
            else
                *num2 ^= data[j];
        }

    }

    unsigned int FindFirstBitIs1(int num){
        int indexBit = 0;
        while(((num & 1) == 0) && (indexBit < 8*sizeof(int))){
            num = num >> 1;
            indexBit++;
        }

        return indexBit;
    }

    bool IsBit1(int num, unsigned int indexBit){
        num = num >> indexBit;
        return (num&1);
    }

};

/**
 * 和为S的连续正数序列
 * */

class Solution42 {
public:
    //自己写的代码不够优美
    vector<vector<int> > FindContinuousSequence(int sum) {

        int index1 = 1;
        int index2 = 1;
        int cursum = 0;
        vector<int>sumres;
        vector<vector<int>>res;
        for(int i = 1; i <=sqrt(sum); i++){
            for( int j = index1; j <= index2; j++){
                cursum = cursum+j;
                sumres.push_back(j);
            }
            if(cursum <sum)
                index2++;
            else if(cursum > sum )
                index1++;
            else if(index2 -index1 >=1){
                res.push_back(sumres);
                index2++;
                index1++;
            }
            sumres.clear();
            cursum =0;
        }
        return res;
    }
    //别人写的双指针索引
    vector<vector<int> > FindContinuousSequence2(int sum) {
        int l = 1,r = 1,sumx = 1;
        vector<vector<int> > ans;
        while(l <= r){
            r ++;
            sumx += r;
            while(sumx > sum){
                sumx -= l;
                l ++;
            }
            if(sumx == sum && l != r){
                vector<int> tmp;
                for(int i = l;i <= r;i ++)  tmp.push_back(i);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};

/**
 * 和为S的两个数组
 * */
class Solution43 {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int l = 0;
        int r = array.size()-1;
        int minsum = INT_MAX;
        //int sum = 0;
        vector<int>minindex;
        while (l < r){
            if(array[l]+array[r] < sum)
                l++;
            else if(array[l]+array[r] > sum)
                r--;
            else {
                if(array[l]*array[r] < minsum)
                {
                vector<int>temp={array[l],array[r]};
                minindex.swap(temp);
                minsum = array[l]*array[r];
                }
                r--;}

        }
        return minindex;
    }
};

/**
 * 左旋转字符串
 * */
class Solution44 {
public:

    //自带函数的解法
    string LeftRotateString(string str, int n) {
        if(n<0) return NULL;
        if(n==0) return str;
        string strTemp="";

        strTemp=str.substr(0,n);
        str.erase(0,n);
        str+=strTemp;
        return str;
    }

    string LeftRotateString2(string str, int n) {
            int len = str.length();
            if(len == 0) return "";
            n = n % len;
            str += str;
            return str.substr(n, len);
    }

    //比较简短的不用内置函数的思路
    string LeftRotateString3(string str, int n)
    {
        int len = str.size();
        if(len == 0) return str;
        n %= len;
        for(int i = 0, j = n - 1; i < j; ++i, --j) swap(str[i], str[j]);
        for(int i = n, j = len - 1; i < j; ++i, --j) swap(str[i], str[j]);
        for(int i = 0, j = len - 1; i < j; ++i, --j) swap(str[i], str[j]);
        return str;
    }

    //底层思路的字符串翻转思想
    void fun(string &s,int start,int end)
    {
        char temp;
        while(start<end)
        {
            temp=s[start];
            s[start]=s[end];
            s[end]=temp;
            start++;
            end--;
        }
    }
    string LeftRotateString4(string str, int n) {
        int len=str.length();
        if(0==len || 0==n)
            return str;
        string &temp=str;
        fun(temp,0,n-1);
        fun(temp,n,len-1);
        fun(temp,0,len-1);
        return str;
    }
};
/**
 * 翻转字符串
 * */

class Solution45 {
public:
    string ReverseSentence(string str) {
        if (str.size()) return str;
        ReverseOneWord(0,str.size()-1,str);
        int s =0,e = 0;
        int i = 0;
        while (i<str.size())
        {
            while(i < str.size() && str[i] == ' ')//空格跳过
                i++;
            e = s =i;//记录单词的第一个字符的位置
            while (i < str.size() && str[i] != ' ')//不是空格 找单词最后一个字符的位置
            {
                i++;
                e++;
            }
            ReverseOneWord(s,e-1,str);
        }
        return  str;

    }

    void ReverseOneWord(int begin,int end,string& str){
        int i = begin;
        int j = end;
        while (i<j)
            swap(str[i++],str[j--]);
    }

    //比较简洁的解法
    string ReverseSentence2(string str) {
        std::reverse(str.begin(),str.end());
        int front=0;
        int back=0;
        int size = str.size();
        while(front<size){
            while(front<size&&str[front]==' ')++front;
            back=front;
            while(back<size&&str[back]!=' ')++back;
            std::reverse(str.begin()+front, str.begin()+back);
            front=back;
        }
        return str;
    }
};

/**
 * 扑克牌顺子
 * */
class Solution46 {
public:
    //比较好的思路
    bool IsContinuous( vector<int> numbers ) {
        if(!numbers.size())
            return false;
        sort(numbers.begin(),numbers.end());
        int numberzero = 0;
        int numbergap = 0;
        for(int i = 0; i < numbers.size()&&numbers[i]== 0;i++)
            numberzero++;
        for(int i = numberzero; i < numbers.size()-1;i++){
            int gap = numbers[i+1] - numbers[i];
            if(gap == 0)
                return false;
            else if(gap > 1)
                numbergap = numbergap +gap-1;
        }
        if(numbergap <= numberzero)
            return true;
        return false;
    }
};

/**
 * 孩子们的游戏
 * */
class Solution47 {
public:
    //链表来模拟环
    int LastRemaining_Solution(int n, int m)
    {
        if(n <1 ||m < 1)
            return -1;
        int i = 0;
        list<int>numbers;
        for(i =0; i < n; i++)
            numbers.push_back(i);
        list<int>::iterator curr = numbers.begin();
        while (numbers.size()>1){
            for( int i = 0; i < m; i++){
                curr++;
                if(curr == numbers.end()){
                    curr = numbers.begin();
                }
            }
            list<int>::iterator next = ++curr;
            if(next == numbers.end())
                next = numbers.begin();
            --curr;
            numbers.erase(curr);
            curr = next;
        }
        return *(curr);

    }
    //用数组来模拟环,这个思路是最好的
    int LastRemaining_Solution1(int n, int m)
    {
        if( n < 1|| m <1)
            return -1;
        vector<int>array(n);
        int i = -1,step = 0,count = n;
        while(count>0){   //跳出循环时将最后一个元素也设置为了-1
            i++;          //指向上一个被删除对象的下一个元素。
            if(i>=n) i=0;  //模拟环。
            if(array[i] == -1) continue; //跳过被删除的对象。
            step++;                     //记录已走过的。
            if(step==m) {               //找到待删除的对象。
                array[i]=-1;
                step = 0;
                count--;
            }
        }
        return i;//返回跳出循环时的i,即最后一个被设置为-1的元素


    }
    int LastRemaining_Solution2(int n, int m)
    {

        if(n==0)
            return -1;
        if(n==1)
            return 0;
        else
            return (LastRemaining_Solution(n-1,m)+m)%n;
    }
};

/**
 * 求１到ｎ的和
 * */

class Solution48 {
public:
    //短路求求值原理
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1));//逻辑与，前面为假，后面不计算
        return ans;
    }
    //求数组个数
    int Sum_Solution２(int n) {
        bool a[n][n+1];
        return sizeof(a)>>1;
    }
};
/**
 * 不用加减乘除的加法
 * */


class Solution49 {
public:
    int Add(int num1,int num2) {
        while (num2!=0) {
            int temp = num1^num2;
            num2 = (num1&num2)<<1;
            num1 = temp;
        }
        return num1;
    }
   //递归版本

    int Add2(int num1, int num2)
    {
        if(num2==0)
            return num1;
        return Add(num1^num2, (num1&num2)<<1);
    }

    int Add3(int num1,int num2) {
        if(num1>0){
            while(num1--!=0)
                num2++;
        }
        else if(num1<0){
            while(num1++!=0)
                num2--;
        }
        return num2;
    }
};


/**
 * 把字符串转换成整数
 * 考虑数据的上下溢出
 * 空字符串
 * 只有正负号
 * 有无正负号
 * 错误标志输出
 * */

class Solution50 {
public:
    int StrToInt(string str) {



    }
};

/**
 * 数组中重复的数字
 * */
class Solution51 {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false


    //第一种是基于通排序的思想，但是额外的空间复杂度可能很大

    //第二种做标志位
    bool duplicate(int numbers[], int length, int* duplication) {
        for (int i = 0; i < length; i++) {

            int index = numbers[i];

            if (index >= length) {

                index -= length;

            }

            if (numbers[index] >= length) {

                return index;

            }

            numbers[index] = numbers[index] + length;

        }

        return -1;
    }

    //比较好的解法
    bool duplicate2(int numbers[], int length, int* duplication) {
        for(int i=0;i!=length;++i){
            int index=numbers[i]%length;
            if(numbers[index]>=length){
                *duplication=index;
                return 1;
            }
            numbers[index]+=length;
        }
        return 0;
    }
    };

/**
 * 构建乘积数组
 * */

class Solution52 {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> vec;
        int sz=A.size();
        if(sz==0)
            return vec;
        vec.push_back(1);
        for(int i=0;i<sz-1;i++)
            vec.push_back(vec.back()*A[i]);
        int tmp=1;
        for(int i=sz-1;i>=0;i--)
        {
            vec[i]=vec[i]*tmp;
            tmp=tmp*A[i];
        }
        return vec;
    }

    vector<int> multiply2(const vector<int>& A) {
       int sz = A.size();
       vector<int>B(sz);
       while(sz!= 0){
           B[0] = 1;
           //计算下三角连乘
           for(int i = 1;i < sz; i++){
               B[i] = B[i-1]*A[i-1];
           }
           int temp = 1;

           for(int j = sz - 2;j >= 0;j--){
               temp *= A[j+1];
               B[j]*=temp;
           }
       }
        return B;
    }

};

/**
 * 正则表达式匹配
 * */
class Solution53 {
public:
    bool match(char* str, char* pattern)
    {
        if(*str == '\0'&& *pattern == '\0')
            return true;
        if(*str != '\0'&& *pattern == '\0')
            return false;
        if(*(pattern+1) != '*'){
            if(*str == *pattern || (*str != '\0'&&*pattern == '.')){
                return match(str+1,pattern+1);
            } else
                return false;
        } else
        {
            if(*str == *pattern || (*str != '\0'&&*pattern == '.'))
                return match(str,pattern+2)||match(str+1,pattern);
            else
                return match(str,pattern+2);
        }

    }
};

/**
 * 表示数值的字符串
 * */
 //此题目求错了
class Solution54 {
public:
    bool isNumeric(char* string)
    {
        //标记符号、小数点、e是否出现
        bool sign = false,decimal = false,hasE = false;
        for(int i = 0; i < strlen(string); i++){
            if(string[i] == 'e'||string[i] == 'E'){
                if( i == strlen(string)-1) return false;//e后面一定要接数字
                if(hasE) return false;
                hasE = true;
            } else if(string[i] == '+'||string[i] == '-'){
                //第二次出现+-符号
                if(sign && string[i-1] != 'e'&& string[i]  != 'E')return false;
                sign = true;
            } else if(string[i] == '.'){
                if(hasE || decimal) return false;
                decimal = true;
            } else if(string[i] < '0'||string[i] > '9')//不合法字符
                return false;

        }
        return  true;

    }

};
/**
 * 字符流中第一个不重复的字符
 * */
//Insert one char from stringstream
class Solution55
{
public:
        void Insert(char ch)
        {
            ++hashArray[ch-'\0'];
            if( hashArray[ch-'\0'] == 1){
                data.push_back(ch);
            }
        }
//return the first appearence once char in current stringstream
        char FirstAppearingOnce()
        {
            while( !data.empty() && hashArray[data.front()] >= 2 ){
                data.pop_front();
            }
            if( data.empty() )
                return '#';
            return data.front();
        }

private:
         unsigned char hashArray[128];
         deque<char> data;//在此学到了一个新的容器，deque是一个双向开口的可进可出的容器，双端队列，是一种具有栈和队列性质的数据结构。双端队列中的元素可以从两端弹出

};

/**
 * 链表中环的入口节点
 * */
class Solution56 {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == nullptr || pHead->next == nullptr || pHead->next->next == nullptr) {
            return nullptr;
        }
        ListNode* n1 = pHead->next;//low指针
        ListNode* n2 = pHead ->next->next;//fast指针
        while (n1 != n2){
            if(n2->next == nullptr || n2->next->next == nullptr){
                return nullptr;
            }
            n2 = n2->next->next;
            n1 = n1->next;
        }
        n2 = pHead;
        while (n1!= n2 ){
            n1 = n1->next;
            n2 = n2->next;
        }
        return n1;

    }
};

/**
 * 删除链表中重复的节点
 * */
class Solution57 {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if( pHead == NULL ) return pHead;

        ListNode *pre = NULL; //指向前面最晚访问过的不重复结点
        ListNode *p = pHead; //指向当前处理的结点
        ListNode *q = NULL; //指向当前处理结点后面结点

        while( p != NULL )
        {
            //当前结点p，（其实是p指向当前结点），与它下一个结点p->next的val相同，说明要删掉有这个val的所有结点
            if( p->next != NULL && p->next->val == p->val )
            {
                q = p->next;

                //找到q，它指向最后一个与p val相同的结点，那p 到 q （包含） 都是要删除的
                while( q != NULL && q->next != NULL && q->next->val == p->val )
                {
                    q = q->next;
                }

                //如果p指向链表中第一个元素，p -> ... -> q ->... , 要删除p到q, 将指向链表第一个元素的指针pHead指向q->next。
                if( p == pHead )
                {
                    pHead = q->next;
                }
                else//如果p不指向链表中第一个元素，pre -> p ->...->q ->... ，要删除p到q，即pre->next = q->next
                {
                    pre->next = q->next;
                }
                //当前处理的p要向链表尾部移动
                p = q->next;
            }
            else
            {
                pre = p;
                p = p->next;
            }
        }
        return pHead;
    }


public:
    //递归版本
    ListNode* deleteDuplication2(ListNode* pHead) {
        if (pHead == nullptr || pHead->next == nullptr) { // 只有0个或1个结点，则返回
            return pHead;
        }
        if (pHead->val == pHead->next->val) { // 当前结点是重复结点
            ListNode* pNode = pHead->next;
            while (pNode != nullptr && pNode->val == pHead->val) {
                // 跳过值与当前结点相同的全部结点,找到第一个与当前结点不同的结点
                pNode = pNode->next;
            }
            return deleteDuplication(pNode); // 从第一个与当前结点不同的结点开始递归
        } else { // 当前结点不是重复结点
            pHead->next = deleteDuplication(pHead->next); // 保留当前结点，从下一个结点开始递归
            return pHead;
        }
    }
};


/**
 * 二叉树的下一个节点
 * 给定一个二叉树和其中的一个节点,找出中序遍历的下一个节点
 * */

struct TreeLinkNode {
   int val;
   struct TreeLinkNode *left;
   struct TreeLinkNode *right;
   struct TreeLinkNode *next;
   TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

   }
};
class Solution58 {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {

        if(pNode==NULL)
            return NULL;
        if(pNode->right!=NULL)
        {
            pNode=pNode->right;
            while(pNode->left!=NULL)
                pNode=pNode->left;
            return pNode;
        }
        while(pNode->next!=NULL)
        {
            TreeLinkNode *proot=pNode->next;
            if(proot->left==pNode)
                return proot;
            pNode=pNode->next;
        }
        return NULL;
    }
};

/**
 * 对称的二叉树
 * */
class Solution59 {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSymmetricalhelp(pRoot,pRoot);
    }

private:
    bool isSymmetricalhelp(TreeNode* pRoot1,TreeNode* pRoot2){
        if(pRoot1 == nullptr&&pRoot2 == nullptr)
            return true;
        if(pRoot1 == nullptr||pRoot2 == nullptr)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        return isSymmetricalhelp(pRoot1->left,pRoot2->right)&&isSymmetricalhelp(pRoot1->right,pRoot2->left);

    }

};

/**
 * 之字型打印数组
 * */
class Solution60 {
public:
    vector<vector<int> > Print(TreeNode* root) {

        if (root == NULL)
            return vector<vector<int>>();

        queue< pair<TreeNode*, int> > q;
        q.push(make_pair(root, 0));
        vector<vector<int>> res;

        while (!q.empty()) {

            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level == res.size())
                res.push_back(vector<int>());
            res[level].push_back(node->val);

            // 接着遍历
            if (node->left)
                q.push(make_pair(node->left, level + 1));
            if (node->right)
                q.push(make_pair(node->right, level + 1));
        }

        // 整理成回形针的形式
        vector<vector<int>> resAli = res;

        for (int i = 1; i < res.size(); i += 2) {
            for (int j = 0; j < res[i].size(); j++) {
                resAli[i][res[i].size() - 1 - j] = res[i][j];
            }
        }

        return resAli;
    }

};
/**
 * 二叉树的序列化与反序列化
 * */

/*
 1. 对于序列化：使用前序遍历，递归的将二叉树的值转化为字符，并且在每次二叉树的结点
不为空时，在转化val所得的字符之后添加一个' ， '作为分割。对于空节点则以 '#' 代替。
 2. 对于反序列化：按照前序顺序，递归的使用字符串中的字符创建一个二叉树(特别注意：
在递归时，递归函数的参数一定要是char ** ，这样才能保证每次递归后指向字符串的指针会
随着递归的进行而移动！！！)
*/
class Solution61 {
public:
    char* Serialize(TreeNode *root) {
        if(root == NULL)
            return NULL;
        string str;
        Serialize(root, str);
        char *ret = new char[str.length() + 1];
        int i;
        for(i = 0; i < str.length(); i++){
            ret[i] = str[i];
        }
        ret[i] = '\0';
        return ret;
    }
    void Serialize(TreeNode *root, string& str){
        if(root == NULL){
            str += '#';
            return ;
        }
        string r = to_string(root->val);
        str += r;
        str += ',';
        Serialize(root->left, str);
        Serialize(root->right, str);
    }

    TreeNode* Deserialize(char *str) {
        if(str == NULL)
            return NULL;
        TreeNode *ret = Deserialize(&str);

        return ret;
    }
    TreeNode* Deserialize(char **str){//由于递归时，会不断的向后读取字符串
        if(**str == '#'){  //所以一定要用**str,
            ++(*str);         //以保证得到递归后指针str指向未被读取的字符
            return NULL;
        }
        int num = 0;
        while(**str != '\0' && **str != ','){
            num = num*10 + ((**str) - '0');
            ++(*str);
        }
        TreeNode *root = new TreeNode(num);
        if(**str == '\0')
            return root;
        else
            (*str)++;
        root->left = Deserialize(str);
        root->right = Deserialize(str);
        return root;
    }
};

/**
 * 二叉搜索树中第k小的节点
 * */

//这题逻辑稍微复杂了点
class Solution62 {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr || k == 0)
            return nullptr;
        return KthNodeCore(pRoot,k);
    }
    TreeNode* KthNodeCore(TreeNode* pRoot,int &k){
        TreeNode* target = nullptr;
        if(pRoot->left)
            target = KthNodeCore(pRoot->left,k);
        if(target == nullptr){
            if(k == 1)
                target = pRoot;
            k--;
        }
        if(target == nullptr&& pRoot->right!= nullptr)
            target = KthNodeCore(pRoot->right,k);
        return  target;
    }

   //
//    int index = 0; //计数器
//    TreeNode KthNode(TreeNode root, int k)
//    {
//        if(root != null){ //中序遍历寻找第k个
//            TreeNode node = KthNode(root.left,k);
//            if(node != null)
//                return node;
//            index ++;
//            if(index == k)
//                return root;
//            node = KthNode(root.right,k);
//            if(node != null)
//                return node;
//        }
//        return null;
//    }
};
/**
 * 数据中的中位数
 * */

//思路做法就是用一个大顶堆和一个小顶堆，维持大顶堆的数都小于等于小顶堆的数，且两者的个数相等或差1。平均数就在两个堆顶的数之中。
class Solution63 {
    priority_queue<int, vector<int>, less<int> > p;
    priority_queue<int, vector<int>, greater<int> > q;

public:
    void Insert(int num){
        if(p.empty() || num <= p.top()) p.push(num);
        else q.push(num);
        if(p.size() == q.size() + 2) q.push(p.top()), p.pop();
        if(p.size() + 1 == q.size()) p.push(q.top()), q.pop();
    }
    double GetMedian(){
        return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
    }
};

/**
 * 滑动窗口的最大值
 * */
class Solution64 {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int>res;
        if(num.size() <size)
            return res;
        int index1 = 0;
        int index2 = index1+size-1;
        while (index2 < num.size()){
            int maxv = INT_MIN;
            for(int i = index1; i <= index2; i++)
                maxv = max(maxv,num[i]);
            res.push_back(maxv);
            index1++;
            index2++;
        }
        return res;
    }
};


/**
 * 单词搜索
 * */
class Solution65 {

private:

    // 搜索映射表
    int d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
    // 网格访问记录表
    vector<vector<bool>> visited;
    // 网格长宽
    int m;	// 行数
    int n;	// 列数

    // 判断一个坐标(x,y)是否在网格中
    bool inArea(int x, int y) {
        if (x >= 0 && x < m && y >= 0 && y < n)
            return true;

        return false;
    }

    // (startX,startY)指向当前要搜索的网格，index指向当前要搜索的字母，程序要做的是从board[startX][startY]开始，寻找word[index...word.size())
    bool searchWord(const vector<vector<char>>& board, const string& word, int index, int startX, int startY) {

        // 终止条件
        if (index == word.size() - 1)
            return board[startX][startY] == word[index];

        // 找到了当前的的对应网格，开始回溯法搜索
        if (board[startX][startY] == word[index]) {
            visited[startX][startY] = true;
            // 从startX和startY出发，向四周寻找下一个匹配网格
            for (int i = 0; i < 4; i++) {
                int newX = startX + d[i][0];
                int newY = startY + d[i][1];
                if (inArea(newX, newY) && !visited[newX][newY]) {
                    if (searchWord(board, word, index + 1, newX, newY))
                        return true;
                }
            }
            // 数据回溯,当前网格往下没有符合的路径
            visited[startX][startY] = false;
        }

        return false;
    }


public:
    bool exist(vector<vector<char>>& board, string word) {

        // 数据初始化
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        // 路径搜索起始点遍历所有网格
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (searchWord(board, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }
};

/**
 * 机器人经典路径问题
 * */
