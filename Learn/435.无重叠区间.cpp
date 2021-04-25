/*
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
注意:
可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-overlapping-intervals
*/
//思路：贪心策略，每次选择一个结尾最小的，为后续选择区间预留更多的空间。  所以先按照每个区间的结尾从小到大进行排序，再进行选择。
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

        sort(intervals.begin(), intervals.end(), myfunction);//排序
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
