/*
三合一。描述如何只用一个数组来实现三个栈。
你应该实现push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法。stackNum表示栈下标，value表示压入的值。
构造函数会传入一个stackSize参数，代表每个栈的大小。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/three-in-one-lcci
*/
//思路：vector的基本用法
#include <vector>
#include <iostream>
using namespace std;
class TripleInOne {
public:
    std::vector<vector<int>> myvector;
    int stackSize;
    TripleInOne(int stackSize) {
        myvector.resize(3, vector<int>());
        this->stackSize = stackSize;
    }

    void push(int stackNum, int value) {
        if (myvector[stackNum].size() == stackSize)return;
        myvector[stackNum].push_back(value);
    }

    int pop(int stackNum) {
        if (myvector[stackNum].size() == 0)return -1;
        int tmp = myvector[stackNum].back();
        myvector[stackNum].pop_back();
        return tmp;
    }

    int peek(int stackNum) {
        if (myvector[stackNum].size() == 0)return -1;
        return myvector[stackNum].back();
    }

    bool isEmpty(int stackNum) {
        return myvector[stackNum].empty();
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */