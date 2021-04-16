/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
说明:
为什么返回数值是整数，但输出的答案是数组呢?
请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
你可以想象内部操作如下:
// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);
// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
*/
//思路：两指针法，但是效率太低，要优化
//优化思路：由于不用考虑后面数组的情况，只需要将后面不一样的数字复制到前面(看评论)，完全不考虑后部分数组的情况
/*
int removeDuplicates(vector<int>& nums) {
        if(nums.size() <2) return nums.size();
        int i=0,j;
        for(j=1;j < nums.size();j++){
            if(nums[i] != nums[j]) nums[++i] = nums[j];
        }
        return i+1;
    }
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 0) return 0;
        int i, j;
        for (i = 0; i < nums.size() - 1; i++) {
            j = i + 1;
            while (nums[i] == nums[j]) {//一直相同，一直向后走
                if (j >= nums.size() - 1) {//一直探索到最后，都相同
                    return i + 1;
                }
                j++;
            }
            while (j > i + 1) {
                nums[j - 1] = nums[j];//赋值
                j--;
            }
        }
        return i + 1;
    }
};