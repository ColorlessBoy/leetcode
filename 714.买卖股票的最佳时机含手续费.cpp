/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

/*
 * Note:
 * dp[state][index]:
 *   - state: 空手state=0, 有股票在手state=1;
 *   - index: 在index时的状态。
 * 状态转移方程：
 * dp[0][index] = max(-prices[index]-fee + dp[1][index+1], 
 *                  dp[0][index+1]);
 * dp[1][index] = max(prices[index] + dp[0][index+1], 
 *                  dp[1][index+1]);
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        array<int, 2> dp = {0, 0};
        int a = 0, b = 0;
        int n = prices.size();
        for(int i = n - 1; i >= 0; --i) {
            int c = a, d = b;
            a = max(-prices[i] - fee + d, c);
            b = max(prices[i] + c, d);
        }
        return a;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    auto rst = s.maxProfit(nums, fee);
    return 0;
}

