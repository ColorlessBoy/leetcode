/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.empty()) return {};
        int n = nums.size(), index = 1;
        vector<int> rst(n, -1);
        stack<int> s; //单调递增栈
        
        for(int i = 0; i < 2 * n; ++i) {
            int index = i % n;
            while(!s.empty() && nums[s.top()] < nums[index]) {
                if(rst[s.top()] == -1)
                    rst[s.top()] = nums[index];
                s.pop();
            }
            s.push(index);
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums = {1, 2, 1};
    auto rst = s.nextGreaterElements(nums);
    return 0;
}

