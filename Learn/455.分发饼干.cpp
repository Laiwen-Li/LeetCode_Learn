/*
假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。
如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，
并输出这个最大数值。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/assign-cookies
*/
//思路：排序+贪心
//存在问题：贪心求解局部最优解的时候，效率太低  优化（copy 101）
//优化思路：寻找局部最优解的时候，孩子和饼干一起向后走，因为当前孩子在前面的饼干中没找到合适的，那说明前面
//的饼干已经全部作废！等找完整个饼干或者孩子已经全部找过饼干，那么全局最优解已经出现！
/*
int child = 0, cookie = 0;
while (child < children.size() && cookie < cookies.size()) {
    if (children[child] <= cookies[cookie]) ++child;
    ++cookie;
}
return child;
*/

#include <iostream>
#include <vector>
#include <algorithm>//std::sort
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.size() < 1)return 0;
        //排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        //贪心
        int i = 0, j = 0, sum = 0, tmp = 0;
        for (i = 0; i < g.size(); i++) {
            for (j = tmp; j < s.size(); j++) {
                if (g[i] <= s[j]) {
                    sum++;
                    tmp = j + 1;
                    s[j] = 0;//被吃掉
                    break;
                }
            }
        }
        return sum;
    }
};