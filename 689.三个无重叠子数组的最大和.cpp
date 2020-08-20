/*
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 */

/*
 * Note:
 * state: 还需要选 state 个不重叠子数组；
 * index: 选 以nums[index]开头 的子数组 作为 第一个子数组。
 * dp[state][index] = dp[0][index] + max_{next_index} dp[state-1][next_index]
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        if(nums.empty()) return {};

        int n = nums.size();
        vector<vector<int>> dp(3, vector<int>(n, 0));

        // 构造 dp[0]
        dp[0][n-1] = nums[n-1];
        for(int i = n - 2; i >= 0; --i) {
            // n - 1 已经计算好了
            dp[0][i] = nums[i] + dp[0][i+1];
            if(i + k < n) 
                dp[0][i] -= nums[i + k];
        }

        // 构造 dp[1] 与 dp[2]
        // dp[1][i] = dp[0][i] + max(dp[0][i+k]);
        // dp[2][i] = dp[0][i] + max(dp[1][i+k]);
        for(int state = 1; state < 3; ++state) {
            vector<int> cur_max(dp[state-1]);
            for(int i = n - state * k; i >= 0; --i) {
                cur_max[i] = max(cur_max[i], cur_max[i+1]);
            }
            for(int i = n - (state + 1) * k ; i >= 0; --i) {
                dp[state][i] = dp[0][i] + cur_max[i + k];
            }
        }
        int cur_max = -1, index = 0, state = 2;
        vector<int> rst;
        for(int i = 0; i <= n - 3 * k; ++i) {
            cur_max = max(cur_max, dp[2][i]);
        }
        while(index < nums.size() && state >= 0 && rst.size() < 3) {
            if(dp[state][index] == cur_max) {
                rst.push_back(index);
                state--;
                cur_max -= dp[0][index];
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
    vector<int> nums = {4, 3, 2, 1};
    int k = 1;
    auto rst = s.maxSumOfThreeSubarrays(nums, k); 
    return 0;
}

