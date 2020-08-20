/*
 * @lc app=leetcode.cn id=664 lang=cpp
 *
 * [664] 奇怪的打印机
 */

/*
 * Note:
 * 从数据来看算法的时间复杂度应该是 O(n^3)；
 * 0. dp[i][j]: i 表示起点， j 表示终点。
 * 1. 连续的相同字母可以简化成一个字母：
 *   - 如果 s[i] == s[i+1], dp[i][j] = dp[i+1][j];
 *   - 如果 s[j] == s[j-1], dp[i][j] = dp[i][j-1];
 * 2. 当 i = j 时， dp[i][j] = 1;
 *    当 i > j 时， dp[i][j] = 0;
 * 3. 在 s[i+1 ... j] 中便利寻找与 s[i] 相同的字符 s[k]，
 *    s[i] 与 s[k] 同时打印， s[i] 与 s[k+1 ... j] 不同时打印:
 *    dp[i][j] = min(d[i][j], dp[i][k-1] + dp[k+1][j]);
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int strangePrinter(string s) {
        if(s.empty()) return 0;
        string s2;
        // 合并连续的相同字母。
        for(auto &ch : s) {
            if(s2.empty() || *(s2.rbegin()) != ch) 
                s2.push_back(ch);
        }
        int n = s2.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return dfs(0, n-1, s2);
    }
private:
    vector<vector<int>> dp;
    int dfs(int i, int j, string &s) {
        if(i > j) {
            return 0;
        }
        else if(dp[i][j] == -1) {
            dp[i][j] = 1 + dfs(i+1, j, s);
            for(int k = i + 1; k <= j; ++k) {
                if(s[k] == s[i]) {
                    dp[i][j] = min(dp[i][j], dfs(i, k-1, s) + dfs(k+1, j, s));
                }
            }
        }
        return dp[i][j];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string str = "bbcbdcddacdaadcdbabdadcdbdccbcdd";
    auto rst = s.strangePrinter(str);
    return 0;
}

