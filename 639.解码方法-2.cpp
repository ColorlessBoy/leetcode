/*
 * @lc app=leetcode.cn id=639 lang=cpp
 *
 * [639] 解码方法 2
 */

/*
 * Note: dp[i] 以下标 i 开头的字符串。
 * if ( s[0] == '0' ) {
 *   //不可能是字符串。 
 * }
 * else if ( s[0] >= '3' && s[0] <= '9' ) {
 *   //当前数字不可能和后面数字联动
 *   dp[0] = dp[1];
 * }
 * else if ( s[0] == '1' ) {
 *   dp[0] = dp[1] + dp[2] * ((s[1] == '*')? 10 : 1);
 * }
 * else if ( s[0] == '2' ) {
 *   dp[0] = dp[1] + dp[2] * ((s[1] == '*')? 7 : 1);
 * }
 * else {
 *   if( s[1] >= '7' && s[1] <= '9' ) {
 *      dp[0] = 9 * dp[1] + dp[2];
 *   }
 *   else if( s[1] >= '0' && s[1] <= '6') {
 *      dp[0] = 9 * dp[1] + 2 * dp[2];
 *   }
 *   else {
 *      dp[0] = 9 * dp[1] + 26 * dp[2];
 *   }
 * }
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0) return 0;
        vector<long long> dp(n, -1);
        return dfs(0, s, dp);
    }
private:
    vector<int> dp;
    int base = 1000000007;
    long long dfs(int idx, string &s, vector<long long> &dp) {
        if(idx == dp.size()) 
            return 1;
        else if(idx > dp.size())
            return 0;
        else if(dp[idx] >= 0)
            return dp[idx];

        if(s[idx] == '0') {
            // 0不可能作为开头。
            dp[idx] = 0;
        }
        else if(idx == s.size() - 1 || s[idx] >= '3' && s[idx] <= '9') {
            // 没有后续数字，或者不能有后续数字。
            dp[idx] = dfs(idx + 1, s, dp);
            if(s[idx] == '*')
                dp[idx] *= 9;
        }
        else if(s[idx] == '1') {
            dp[idx] = dfs(idx + 1, s, dp);
            if(s[idx + 1] == '*') {
                dp[idx] += 9 * dfs(idx + 2, s, dp);
            }
            else {
                dp[idx] += dfs(idx + 2, s, dp);
            }
        }
        else if(s[idx] == '2') {
            dp[idx] = dfs(idx + 1, s, dp);
            if(s[idx + 1] == '*') {
                dp[idx] += 6 * dfs(idx + 2, s, dp);
            }
            else if(s[idx + 1] >= '0' && s[idx + 1] <= '6'){
                dp[idx] += dfs(idx + 2, s, dp);
            }
        }
        else {
            dp[idx] = 9 * dfs(idx + 1, s, dp);
            if( s[idx + 1] >= '7' && s[idx + 1] <= '9' ) {
                dp[idx] += dfs(idx + 2, s, dp);
            }
            else if( s[idx + 1] >= '0' && s[idx + 1] <= '6') {
                dp[idx] += 2 * dfs(idx + 2, s, dp);
            }
            else {
                dp[idx] += 15 * dfs(idx + 2, s, dp);
            }
        }
        dp[idx] %= base;
        return dp[idx];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string str = "2839";
    auto rst = s.numDecodings(str);
    return 0;
}

