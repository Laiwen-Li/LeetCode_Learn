/*
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，
因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。
一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 
且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。
我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。
给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons
*/
//思路：每次寻找重叠区间的最小范围，也就是气球重叠最多的部分
//注意：一定要按照头去比较，因为存在条件xstart < xend。如果按照尾去比较，头就有各种情况！！！
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    static bool myfuntion(vector<int>a, vector<int>b) {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() < 1)return 0;
        //排序
        sort(points.begin(), points.end(), myfuntion);

        int count = 1;
        int min_start = points[0][0];//重叠区间头
        int max_end = points[0][1];//重叠区间尾
        //每次寻找最小的重叠区间
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= max_end) {
                min_start = points[i][0];//更新重叠区间头
            }
            else {//火箭数++，更新重叠区间头，尾
                count++;
                min_start = points[i][0];
                max_end = points[i][1];
            }
            if (points[i][1] <= max_end) {//更新重叠区间尾
                max_end = points[i][1];
            }
        }
        return count;
    }
};