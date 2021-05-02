/*
实现一个MyQueue类，该类用两个栈来实现一个队列。

示例：
MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-queue-using-stacks-lcci
*/
//目的：练习STL中的stack
//思路:栈和队列push的时候，看不出区别，但是当pop或者peek时，就不一样。pop的顺序正好相反，那么栈pop两次的顺序就和队列pop一次的顺序相同。
//push时，直接存入stackWrite中，pop时，先将stackWrite中的元素pop到stackRead中，再从stackRead中pop一个元素。
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    std::stack<int> stackWrite;
    std::stack<int> stackRead;
    /** Initialize your data structure here. */
    MyQueue() {
        //两个队列清空
        while (!stackWrite.empty()) {
            stackWrite.pop();
        }
        while (!stackRead.empty()) {
            stackRead.pop();
        }
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stackWrite.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp;
        if (!stackRead.empty()) {//首先判断stackRead是否为空
            tmp = stackRead.top();
            stackRead.pop();
            return tmp;
        }
        else {
            while (!stackWrite.empty()) {
                tmp = stackWrite.top();
                stackWrite.pop();
                stackRead.push(tmp);
            }
            tmp = stackRead.top();
            stackRead.pop();
            return tmp;
        }
    }

    /** Get the front element. */
    int peek() {
        if (!stackRead.empty()) {
            return stackRead.top();
        }
        else {
            int tmp;
            while (!stackWrite.empty()) {
                tmp = stackWrite.top();
                stackWrite.pop();
                stackRead.push(tmp);
            }
            return stackRead.top();
        }
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if (stackWrite.empty() && stackRead.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */