/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

/*
 * Note:
 * sum: sum of nums; 
 * dp[0 ... sum + target];
 * dp[i] : 保存和为i的添加符号的方法数。
 * dp[i] += dp[i - 2 * nums[j]];
 * 状态压缩：因为只有偶数下标的dp有效。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(auto &n: nums) {
            sum += n;
        }
        if(((sum ^ S) & 1) || sum < S) return 0;
        int top = (sum + S)/2;
        vector<int> dp(top+1, 0);
        dp[0] = 1;
        for(auto &n: nums) {
            for(int j = top; j >= n; --j) {
                dp[j] += dp[j - n];
            }
        }
        return dp[top];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    int S = 3;
    auto rst = s.findTargetSumWays(nums, S);
    return 0;
}

