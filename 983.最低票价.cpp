/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = *(days.rbegin());
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for(auto &d: days) {
            dp[d] = 0;
        }
        int rst = INT_MAX;
        for(int i = 1; i <= n; ++i) {
            if(dp[i] == 0) {
                dp[i] = dp[i-1] + costs[0];
                dp[i] = min(dp[i], dp[max(0, i-7)] + costs[1]);
                dp[i] = min(dp[i], dp[max(0, i-30)] + costs[2]);
                rst = dp[i];
            }
            else {
                dp[i] = dp[i-1];
            }
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {7, 2, 15};
    auto rst = s.mincostTickets(days, costs);
    return 0;
}

