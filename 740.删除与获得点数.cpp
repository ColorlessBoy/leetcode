/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除与获得点数
 */

/*
 * Notes:
 * dp[i]: 实数区间 [i ... 10000] 能获得的最大点数。
 * dp[i] = max(i * counts[i] + dp[i+2], dp[i+1]);
 * dp 和 counts 可以是同一个数组。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int dp[10003] = {};
        int top = 0;
        for(auto &n : nums) {
            top = max(top, n);
            dp[n]++;
        }
        for(int i = top; i > 0; --i) {
            dp[i] = max(i * dp[i] + dp[i+2], dp[i+1]);
        }
        return dp[1];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

