/*
 * @lc app=leetcode.cn id=576 lang=cpp
 *
 * [576] 出界的路径数
 */

/*
    dp[50][50][N]:
    dp[i][j][1] = 1;
*/

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if(N == 0) return 0;
        int base = 1000000007;
        vector<vector<int>> dp(m + 2, vector<int>(n + 2, 0));
        dp[i+1][j+1] = 1;
        vector<vector<int>> cnt(dp);
        for(int epoch = 1; epoch < N; ++epoch) {
            vector<vector<int>> tmp(dp);
            for(int i = 1; i <= m; ++i) {
                for(int j = 1; j <= n; ++j) {
                    dp[i][j] = ((tmp[i-1][j] + tmp[i+1][j]) % base
                              + (tmp[i][j-1] + tmp[i][j+1]) % base) % base;
                    cnt[i][j] = (cnt[i][j] + dp[i][j]) % base;
                }
            }
        }
        int rst = 0;
        for(int i = 1; i <= m; ++i) {
            rst = (rst + cnt[i][1]) % base;
            rst = (rst + cnt[i][n]) % base;
        }
        for(int j = 1; j <= n; ++j) {
            rst = (rst + cnt[1][j]) % base;
            rst = (rst + cnt[m][j]) % base;
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    auto rst = s.findPaths(1, 3, 3, 0, 1);
    return 0;
}

