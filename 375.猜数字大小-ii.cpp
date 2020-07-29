/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */
/*
    1. 应该是要动态规划，感觉上有点类似扔鸡蛋问题。
    2. dp[i][j] 表示[i ... j]之间该如何猜，能节省花费。
    3. 状态转移：
       dp[i][j] = min_k + max(dp[i][k-1], dp[k+1][j])
*/
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int getMoneyAmount(int n) {
        table = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return dp(1, n);
    }
private:
    vector<vector<int>> table;
    int dp(int i, int j) {
        if(i >= j) {
            return 0;
        }
        if(table[i][j] != -1) {
            return table[i][j];
        }
        int rst = 0x7fffffff;
        for(int k = i; k <= j; ++k) {
            rst = min(rst, k + max(dp(i, k-1), dp(k+1, j)));
        }
        table[i][j] = rst;
        return rst;
    }
};
// @lc code=end

