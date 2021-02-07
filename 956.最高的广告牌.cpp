/*
 * @lc app=leetcode.cn id=956 lang=cpp
 *
 * [956] 最高的广告牌
 */

/*
 * Notes:
 *   非常特别的背包问题。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        if(rods.size() <= 1) return 0;
        int N = rods.size(), LEN = 0;
        for(auto rod: rods) {
            LEN += rod;
        }
        LEN /= 2;
        vector<int> dp(2 * LEN + 1, INT_MIN), dp_next(2 * LEN + 1, INT_MIN);
        dp[0 + LEN] = 0;
        for(auto rod: rods) {
            for(int i = -LEN; i <= LEN; ++i) {
                dp_next[i + LEN] = dp[i + LEN];
                if(i - rod >= -LEN) {
                    dp_next[i + LEN] = max(dp_next[i + LEN], dp[i - rod + LEN] + rod);
                }
                if(i + rod <= LEN) {
                    dp_next[i + LEN] = max(dp_next[i + LEN], dp[i + rod + LEN]);
                }
            }
            swap(dp, dp_next);
        }
        return dp[0 + LEN];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> rods = {5, 5};
    int rst = s.tallestBillboard(rods);
    return 0;
}

