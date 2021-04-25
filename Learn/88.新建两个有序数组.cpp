/*
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它
就有足够的空间保存来自 nums2 的元素。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
*/
/*
提示：
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[i] <= 109
*/
//思路：双指针，重点在于两个指针要从后向前遍历！！！！
/*借鉴代码
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m-- + n-- - 1;
        while (m >= 0 && n >= 0) {
            nums1[pos--] = nums1[m] > nums2[n]? nums1[m--]: nums2[n--];
        }
        while (n >= 0) {
            nums1[pos--] = nums2[n--];
        }
    }
};
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1;//记录要插入的位置
        m--;//使用m n作为两个指针
        n--;
        while (m > 0 && n > 0) {
            if (nums1[m] >= nums2[n]) {
                nums1[pos--] = nums1[m--];
            }
            else {
                nums1[pos--] = nums2[n--];
            }
        }
        while (n > 0) {
            nums1[pos--] = nums2[n--];
        }
    }
};