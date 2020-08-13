/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

/*
 * Note:
 *   dp[i][j]: s[i...j]之间的最长回文子序列。
 *   状态转移方程为:
 *   dp[i][j] = max(dp[i][j-1], dp[i+1][j], 
 *     dp[i+1][j-1] + 2*(s[i] == s[i+delta-1]));
 *   
 *   接下来降低空间复杂度。
 *   dp[i][delta]: s[i...i+delta-1]之间的最长回文子序列。
 *   状态转移方程为:
 *   dp[i][delta] = max(dp[i][delta-1], dp[i+1][delta-1],
 *     dp[i+1][delta-2] + 2*(s[i] == s[i+delta-1]));
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // 避免处理奇偶性。
        int n = s.size();
        int top = 2 * n - 1;
        string p(top, '#');
        for(int i = 0; i < n; ++i) {
            p[2 * i] = s[i];
        }

        vector<int> dp(top, 0);
        for(int i = 0; i < top; i += 2) {
            dp[i] = 1;
        }
        for(int delta = 3; delta <= top; delta += 2) {
            for(int i = 0; i + delta - 1 < top; ++i) {
                if(p[i] == '#') {
                    dp[i] = dp[i+1]; 
                    // 等价于保存 dp[i+1][delta-2];
                }
                else {
                    // 初始时，dp[i] 等价于分析中的 dp[i][delta-1]
                    if(p[i] == p[i + delta - 1])
                        dp[i] = max(dp[i], dp[i+1]+2);
                    // dp[i+2] 等价于分析中的 dp[i+1][delta-1]
                    dp[i] = max(dp[i], dp[i+2]);
                }
            }
        }
        return dp[0];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string str = "aabaaba";
    auto rst = s.longestPalindromeSubseq(str);
    return 0;
}

