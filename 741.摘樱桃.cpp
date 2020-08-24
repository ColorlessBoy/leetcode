/*
 * @lc app=leetcode.cn id=741 lang=cpp
 *
 * [741] 摘樱桃
 */

/*
 * Notes:
 * 1. 单程很简单：
 *    dp[i][j] = value[i][j] 
 *      + max(dp[i-1][j], dp[i][j-1]);
 * 2. 我们做两轮单程。每轮贪心地取最大值;
 * 3. 这道题的特别是：如何在遍历的时候留下痕迹。
 * 很不幸，贪心法不对。
 * 1. dp[i][j][state]: state = 1 或 2。
 *    dp[i][j][1] = value[i][j] + max(dp[i-1][1], dp[i][j-1][1]);
 * 2. 难点在于 dp[i][j][2] 的状态转移方程。
 *    dp[i][j][2] = max(dp[i-1][j][2], dp[i][j-1][2], dp2(i-1, j, 1, i, j-1, 1));
 *    dp2(i-1, j, 1, i, j-1, 1) 表示 dp[i][j][2] 两条路分别从上面和左边到达 (i, j)。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        if(n == 0) return 0;
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        int rst;
        if((rst = dp(m-1, n-1, grid)) < 0) {
            // 无法到达。
            return 0;
        }
        int i = m - 1, j = n - 1;
        while(i != 0 && j != 0) {
            grid[i][j] = 0;
            if(memo[i-1][j] >= memo[i][j-1]) {
                i--;
            }
            else {
                j--;
            }
        }
        while(i > 0) grid[i--][j] = 0;
        while(j >= 0) grid[i][j--] = 0;

        memo = vector<vector<int>>(m, vector<int>(n, -1));
        rst += dp(m-1, n-1, grid);
        return rst;
    }
private:
    vector<vector<int>> memo;
    int dp(int i, int j, vector<vector<int>> &grid) {
        if(i == 0 && j == 0) {
            memo[i][j] = grid[i][j];
        }
        else if(i < 0 || j < 0) {
            return -1000;
        }
        if(memo[i][j] < 0) {
            if (grid[i][j] == -1) {
                memo[i][j] = -1000;
            }
            else {
                memo[i][j] = grid[i][j] + 
                            max(dp(i, j - 1, grid),
                                dp(i - 1, j, grid));
            }
        }
        return memo[i][j];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    // vector<vector<int>> grid = {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
    // vector<vector<int>> grid = {{1}};
    vector<vector<int>> grid = 
        {{1,1,1,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,1},{1,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,1,1,1}};
    auto rst = s.cherryPickup(grid);
    return 0;
}

