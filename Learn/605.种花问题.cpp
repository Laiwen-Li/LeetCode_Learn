/*
假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
给你一个整数数组  flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则的
情况下种入 n 朵花？能则返回 true ，不能则返回 false。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/can-place-flowers
*/
//思路：贪心策略，当前位置能种花，就直接种花
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n < 1)return true;
        for (int i = 0; i < flowerbed.size(); i++) {//直接根据能种花的条件，进行判断
            if (flowerbed[i] == 0 && (i + 1 == flowerbed.size() || flowerbed[i + 1] == 0) && (i == 0 || flowerbed[i - 1] == 0)) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};