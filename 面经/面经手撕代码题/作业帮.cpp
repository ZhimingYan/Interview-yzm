#include "head.hpp"
// 快牌
void quickSort(int q[], int l , int r){
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while( i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i] , q[j]);
        
    }
    quickSort(q,l,j);
    quickSort(q,j+1, r);
} 

//二叉树的层序便利，太简单了

//写一个洗牌程序
//朴素做法
void Shuffle(int n){
    for(int i = n -1 ; i >= 1; i--){
        swap(nums[i],nums[rand()%(i+1)]);
    }
}
//
srand(time(NULL));
for(int i = 0; i < N ; i++){
    int temp = rand() % (i+1);
    if(temp != i)
        swap((poker[i],poker[temp])

//如何证明？
