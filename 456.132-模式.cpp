/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
 */

// 这个和栈有什么关系呢？

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        vector<int> premin(n);//前缀最小数组
        int mi = nums[0];
        for(int i = 1; i < n - 1; ++i) {
            premin[i] = mi;
            mi = min(mi, nums[i]);
        }

        stack<int> s; //单调递减栈
        s.push(nums[n - 1]);
        for(int i = n - 2; i > 0; --i) {
            int mi = premin[i];
            while(!s.empty() && mi >= s.top()) {
                s.pop();
            }
            if(!s.empty() && s.top() < nums[i]) {
                return true;
            }
            if(s.empty() || nums[i] < s.top()) {
                s.push(nums[i]);
            }
        }
        return false;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums = {-2, 1, -2};
    auto rst = s.find132pattern(nums);
    return 0;
}

