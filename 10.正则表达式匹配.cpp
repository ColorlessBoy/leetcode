/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        //从后往前遍历。
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[m][n] = true;
        for(int j = n - 1; j >= 0; --j) {
            if(p[j] == '*') {
                dp[m][j] = dp[m][j+1];
                dp[m][j-1] = dp[m][j];
                --j;
            }
        }
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                if(p[j] == '*') {
                    if(p[j-1] == '.' || p[j-1] == s[i]) {
                        dp[i][j] = dp[i][j+1] | dp[i+1][j+1] | dp[i+1][j];
                        dp[i][j-1] = dp[i][j];
                    }
                    else {
                        dp[i][j] = dp[i][j+1];
                        dp[i][j-1] = dp[i][j];
                    }
                    j--;
                }
                else {
                    if(p[j] == '.' || p[j] == s[i]) {
                        dp[i][j] = dp[i+1][j+1];
                    }
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string s1 = "a", s2 = "ab*";
    auto rst = s.isMatch(s1, s2);
    return 0;
}

