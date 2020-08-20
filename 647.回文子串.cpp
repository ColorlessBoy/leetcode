/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

/*
 * Note:
 * 回文子串有没有什么公共子问题，可以避免重复求解？
 * dp[i][j] = ((s[i] == s[j]) & dp[i+1][j-1]);
 * 沿着对角线遍历。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty()) return 0;
        int n = s.size(), cnt = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // 对角线1
        for(int i = 0; i < n; ++i) 
            dp[i][i] = 1;

        cnt = n;

        // 对角线2
        for(int i = 0; i < n - 1; ++i) {
            if(dp[i][i + 1] = (s[i] == s[i+1]))
                cnt++;
        }

        // 其他对角线
        for(int j = 2; j < n; ++j) {
            for(int i = 0; i < n - j; ++i) {
                if(s[i] == s[i + j] && dp[i+1][i + j - 1]) {
                    dp[i][i + j] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

