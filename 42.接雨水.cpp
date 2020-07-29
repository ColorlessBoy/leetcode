/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// 1. 解法1：单调栈。
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int n = height.size(), cnt = 0;
        stack<int> s;
        for(int i = 0; i < n; ++i) {
            int h = height[i];
            while(!s.empty() && height[s.top()] < h) {
                int j = s.top(); s.pop();
                if(!s.empty()) {
                    int distance = i - s.top() - 1;
                    int delta_h = min(height[s.top()], h) - height[j];
                    cnt += distance * delta_h;
                }
            }
            s.push(i);
        }
        return cnt;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int rst = s.trap(nums);
    return 0;
}

