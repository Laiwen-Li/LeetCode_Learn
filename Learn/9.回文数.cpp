/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-number
*/
//思路：反转整数，判断与原数是否相等。  考虑如何优化
/*
优化思路：对整数只反转一半，判断两个数是否相等
存在一个问题：对于10 100 1000 ....之类的数据，无法通过此方法获取正确结果，要预先处理，因为最后一位是0的肯定不是回文数
*/
/*
bool isPalindrome(int x) {
        if(x < 0) return  false;
        if(x > 0 && x%10 == 0)return false;//预先处理掉10 100 1000之类的数据，但是要排除0
        int tmp=0;
        while(x > tmp){
            tmp = tmp*10 + x%10;
            x = x/10;
        }
        if(tmp == x || x == tmp/10) return true;
        else return false;
    }
*/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return  false;
        int a = x;
        int tmp = 0;
        while (x > 0) {
            //溢出判断  反转溢出的，肯定不是回文数
            if ((tmp > INT_MAX / 10) || (tmp == INT_MAX / 10 && x % 10 > 7)) return false;
            tmp = tmp * 10 + x % 10;
            x = x / 10;
        }
        if (tmp == a) return true;
        else return false;
    }
};