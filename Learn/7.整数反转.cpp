﻿/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
假设环境不允许存储 64 位整数（有符号或无符号）。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
*/
//重点：数据溢出的判断与处理，在将要溢出之前判断是否会溢出
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int a = 0;
        while (x != 0) {
            if (a > INT_MAX / 10 || (a == INT_MAX / 10 && x % 10 > 7)) return 0;
            if (a < INT_MIN / 10 || (a == INT_MIN / 10 && x % 10 < -8)) return 0;
            a = a * 10 + x % 10;
            x = x / 10;
        }
        return a;
    }
};