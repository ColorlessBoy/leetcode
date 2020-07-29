/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

/*
 * 1. 直觉：动态规划。
 * 2. 状态转移方程：
 *  dp[1] = 1;
 *  dp[t] = dp[t-nums[0]] + dp[t-nums[1]] + ... + dp[t-nums[n]];
*/
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        memo.resize(target+1, -1);
        dp(nums, target);
        return memo[target];
    }
private:
    vector<int> memo;
    int dp(vector<int>& nums, int target) {
        if(target < 0) {
            return 0;
        }
        else if(target == 0) {
            return 1;
        }
        else if(memo[target] != -1) {
            return memo[target];
        }
        int rst = 0;
        for(auto num: nums) {
            rst += dp(nums, target-num);
        }
        memo[target] = rst;
        return rst;
    }
};
// @lc code=end

