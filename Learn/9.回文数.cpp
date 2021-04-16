/*
����һ������ x ����� x ��һ���������������� true �����򣬷��� false ��

��������ָ���򣨴������ң��͵��򣨴������󣩶�����һ�������������磬121 �ǻ��ģ��� 123 ���ǡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/palindrome-number
*/
//˼·����ת�������ж���ԭ���Ƿ���ȡ�  ��������Ż�
/*
�Ż�˼·��������ֻ��תһ�룬�ж��������Ƿ����
����һ�����⣺����10 100 1000 ....֮������ݣ��޷�ͨ���˷�����ȡ��ȷ�����ҪԤ�ȴ�����Ϊ���һλ��0�Ŀ϶����ǻ�����
*/
/*
bool isPalindrome(int x) {
        if(x < 0) return  false;
        if(x > 0 && x%10 == 0)return false;//Ԥ�ȴ����10 100 1000֮������ݣ�����Ҫ�ų�0
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
            //����ж�  ��ת����ģ��϶����ǻ�����
            if ((tmp > INT_MAX / 10) || (tmp == INT_MAX / 10 && x % 10 > 7)) return false;
            tmp = tmp * 10 + x % 10;
            x = x / 10;
        }
        if (tmp == a) return true;
        else return false;
    }
};