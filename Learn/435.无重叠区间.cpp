/*
����һ������ļ��ϣ��ҵ���Ҫ�Ƴ��������С������ʹʣ�����以���ص���
ע��:
������Ϊ������յ����Ǵ���������㡣
���� [1,2] �� [2,3] �ı߽��໥���Ӵ�������û���໥�ص���
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/non-overlapping-intervals
*/
//˼·��̰�Ĳ��ԣ�ÿ��ѡ��һ����β��С�ģ�Ϊ����ѡ������Ԥ������Ŀռ䡣  �����Ȱ���ÿ������Ľ�β��С������������ٽ���ѡ��
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    static bool  myfunction(vector<int>a, vector<int>b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() < 1)return 0;

        sort(intervals.begin(), intervals.end(), myfunction);//����
        int i = 0, sum = 0, tmp = intervals[0][1];
        for (i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < tmp) {
                sum++;
            }
            else {
                tmp = intervals[i][1];
            }
        }
        return sum;
    }
};
