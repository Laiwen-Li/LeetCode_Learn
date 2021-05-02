/*
ʵ��һ��MyQueue�࣬����������ջ��ʵ��һ�����С�

ʾ����
MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);
queue.peek();  // ���� 1
queue.pop();   // ���� 1
queue.empty(); // ���� false
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/implement-queue-using-stacks-lcci
*/
//Ŀ�ģ���ϰSTL�е�stack
//˼·:ջ�Ͷ���push��ʱ�򣬿��������𣬵��ǵ�pop����peekʱ���Ͳ�һ����pop��˳�������෴����ôջpop���ε�˳��ͺͶ���popһ�ε�˳����ͬ��
//pushʱ��ֱ�Ӵ���stackWrite�У�popʱ���Ƚ�stackWrite�е�Ԫ��pop��stackRead�У��ٴ�stackRead��popһ��Ԫ�ء�
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    std::stack<int> stackWrite;
    std::stack<int> stackRead;
    /** Initialize your data structure here. */
    MyQueue() {
        //�����������
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
        if (!stackRead.empty()) {//�����ж�stackRead�Ƿ�Ϊ��
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