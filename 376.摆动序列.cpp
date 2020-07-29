/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return n;

        int flag = 0, cnt = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i-1] < nums[i]) {
                if(flag == -1) {
                    cnt++;
                }
                flag = 1;
            }
            else if(nums[i-1] > nums[i]) {
                if(flag == 1) {
                    cnt++;
                }
                flag = -1;
            }
        }
        // flag == 0 表示数组的数都相等。
        return (flag == 0)? 1 : cnt + 2;
    }
};
// @lc code=end

