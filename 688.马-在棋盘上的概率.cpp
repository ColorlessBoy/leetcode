/*
 * @lc app=leetcode.cn id=688 lang=cpp
 *
 * [688] “马”在棋盘上的概率
 */

/*
 * Note:
 * 搜索空间成指数增加，必须进行状态压缩。
 * 1. dp[r][c][k] = 
 *      dp[r+2][c+3][k-1]
 *    + dp[r+2][c-3][k-1]
 *    + ...
 *    + dp[r-3][c-3][k-1]
 * 2. dp[r][c][k] ?= dp[r][c][k-1]
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        dp = vector<vector<vector<double>>> (N, vector<vector<double>>(N, vector<double>(K + 1, 2.0)));
        return dfs(r, c, K, N);
    }
private:
    vector<vector<vector<double>>> dp;
    double dfs(int r, int c, int k, int N) {
        if(r < 0 || r >= N || c < 0 || c >= N) {
            return 0.0;
        }
        else if(k <= 0) {
            return 1.0;
        }
        else if(dp[r][c][k] <= 1.0) {
            return dp[r][c][k];
        }
        else {
            dp[r][c][k] = dfs(r+1, c+2, k-1, N)
                        + dfs(r+1, c-2, k-1, N)
                        + dfs(r-1, c+2, k-1, N)
                        + dfs(r-1, c-2, k-1, N)
                        + dfs(r+2, c+1, k-1, N)
                        + dfs(r+2, c-1, k-1, N)
                        + dfs(r-2, c+1, k-1, N)
                        + dfs(r-2, c-1, k-1, N);
            dp[r][c][k] /= 8.0;
        }
        return dp[r][c][k];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    auto rst = s.knightProbability(3, 2, 0, 0);
    return 0;
}

