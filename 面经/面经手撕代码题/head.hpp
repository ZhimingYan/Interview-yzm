#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<queue>
#include<stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };