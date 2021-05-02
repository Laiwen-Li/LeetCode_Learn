/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
*/
//思路：方法1：4个指针+循环   方法2：递归(最合适的做法)
//看评论：递归的重点在于找到合适的终止条件，不能一直递归下去。
/*核心内容：
* if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;//当前循环层返回值
        }
        else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
终止条件：
if(l1 == NULL)return l2;
if(l2 == NULL)return l1;
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)return l2;//终止条件
        if (l2 == NULL)return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};