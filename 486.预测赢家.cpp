/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */

/*
 * Note:
 * 动态规划数组：
 * dp[i][j] = max(-dp[i+1][j]+nums[i], -dp[i][j-1]+nums[j]);
 * 数组dp[i][j]表示数组为nums[i...j]时，先手玩家能获得的分数。
 * 
 * 优化：
 * dp[i][delta]表示数组为nums[i...i+delta]时，先手玩家能获得的分数。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.empty()) return true;
        int n = nums.size();
        vector<int> dp(nums);
        for(int delta = 2; delta <= n; ++delta) {
            for(int i = 0; i + delta <= n; ++i) {
                dp[i] = max(-dp[i]+nums[i+delta-1], 
                                    -dp[i+1]+nums[i]);
            }
        }
        return dp[0] >= 0;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums = {1, 5, 2};
    auto rst = s.PredictTheWinner(nums);
    return 0;
}

