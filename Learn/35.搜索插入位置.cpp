/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。
示例 1:
输入: [1,3,5,6], 5
输出: 2
示例 2:
输入: [1,3,5,6], 2
输出: 1
示例 3:
输入: [1,3,5,6], 7
输出: 4
示例 4:
输入: [1,3,5,6], 0
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-insert-position
*/
//思路：非常明显的一道二分查找题目
//优化思路：其中的ans变量就是left，所以ans可以去掉
/*
int left = 0, right = nums.size()-1;
int min = 0;
while(left <= right){
    min = (left + right)/2;
    if(nums[min] == target){
        return min;
    }
    else if(nums[min] > target){
        right = min - 1;
    }
    else {
        left = min + 1;
    }
}
return left;
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int min = 0;
        int ans = nums.size();
        while (left <= right) {
            min = (left + right) / 2;
            if (nums[min] == target) {
                return min;
            }
            else if (nums[min] > target) {
                ans = min;
                right = min - 1;
            }
            else {
                left = min + 1;
            }
        }
        return ans;
    }
};