/*
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 */

/*
 * Note:
 * state: 还需要选 state 个不重叠子数组；
 * index: 选 以nums[index]开头 的子数组 作为 第一个子数组。
 * 0. sums[index] 表示以 nums[index] 开头长度为k的子数组 的和。
 * 1. dp[state][index] = sums[index] 
 *      + max_{next_index} dp[state-1][next_index]。
 * 2. dp[0][index] 非常特别，相当于以nums[index]开头c长度为k的子串。
 *    所以它会有更多的用途。
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        if(nums.empty()) return {};
        int n = nums.size();
        
        // nums是正整数数组，所以dp初始化可以为0。
        vector<vector<int>> dp(3, vector<int>(n, 0));

        // 构造 dp[0]
        dp[0][n-1] = nums[n-1];
        for(int i = n - 2; i >= 0; --i) {
            dp[0][i] = nums[i] + dp[0][i+1];
            if(i + k < n) 
                dp[0][i] -= nums[i + k];
        }

        // dp[0]可以有多种用途，所以用一个别名来强调。
        // sums[index] 表示以 nums[index] 开头， 长度为 k 的子数组的和。
        vector<int>& sums = dp[0];

        for(int state = 1; state < 3; ++state) {
            //先构造max数组，降低时间复杂度。
            vector<int> next_max(dp[state-1]);
            for(int i = n - state * k - 1; i >= 0; i --) {
                // next_max[n - state * k] 是最后一个子数组串，不用比较。
                next_max[i] = max(next_max[i], next_max[i+1]);
            }
            for(int i = 0; i <= n - (state + 1) * k; ++i) {
                // next_max[n - state * k] 是最后一个子数组串，所以需要在多移动一个子数组。
                dp[state][i] = sums[i] + next_max[i + k];
            }
        }

        // 还原最大值
        // 1. 首先找出最大值
        int max_sum = 0;
        for(int i = 0; i < n; ++i) {
            max_sum = max(max_sum, dp[2][i]);
        }
        vector<int> rst;
        int index = 0, state = 2;
        while(index < n && state >= 0 && rst.size() < 3) {
            if(dp[state][index] == max_sum) {
                rst.push_back(index);
                max_sum -= sums[index];
                state--;
                index += k;
            }
            else {
                index++;
            }
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums = {1,2,1,2,6,7,5,1};
    int k = 2;
    auto rst = s.maxSumOfThreeSubarrays(nums, k); 
    return 0;
}

