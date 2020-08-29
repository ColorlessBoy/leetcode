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
 * 
 * 1. dp[r1][c1][r2][c2] 表示
 *    两个人分别从 (r1, c1) 和 (r2, c2) 出发， 走到 (N-1, N-1) 点能获得的最大草莓数量；
 * 2. dp[r1][c1][r2][c2] = value(r1, c1, r2, c2) + max(
 *      dp[r1+1][c1][r2+1][c2], dp[r1+1][c1][r2][c2+1],
 *      dp[r1][c1+1][r2+1][c2], dp[r1][c1+1][r2][c2+1] 
 *    );
 * 3. r1 + c1 == r2 + c2, 所以动态规划矩阵可以减少一个维度，也就是：
 *    dp[k][r1][r2], 其中 k = r1 + c1 = r2 + c2;
 *    dp[k][r1][r2] = value(k, r1, r2) + max(
 *      dp[k+1][r1][r2], dp[k+1][r1][r2+1],
 *      dp[k+1][r1+1][r2], dp[k+1][r1+1][r2+1],
 *    )
 * 4. 使得 r1 >= r2, 又可以减少一半的访问。
 * 5. k = 2*N-2 ... 0;
 *      r1 = max(k - N + 1, 0) ... min(k, N - 1);
 *      r2 = max(k - N + 1, 0) ... r1;
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int N = grid.size();
        vector<vector<int>> dp(N+1, vector<int>(N+1, INT_MIN));
        dp[N-1][N-1] = grid[N-1][N-1];
        for(int k = 2 * N - 3 ; k >= 0; --k) {
            for(int r1 = max(k - N + 1, 0); r1 <= min(N - 1, k); ++r1) {
                for(int r2 = max(k - N + 1, 0); r2 <= r1; ++r2) {
                    int c1 = k - r1, c2 = k - r2;
                    if(c2 >= N) continue;
                    if(grid[r1][c1] == -1 || grid[r2][c2] == -1) {
                        dp[r1][r2] = INT_MIN;
                    }
                    else {
                        dp[r1][r2] = max(
                                max(dp[r1+1][r2+1], dp[r1+1][r2]),
                                max(dp[r1][r2+1], dp[r1][r2])
                            );
                        if(dp[r1][r2] != INT_MIN) {
                            if(r1 == r2) {
                                dp[r1][r2] += grid[r1][c1];
                            }
                            else {
                                dp[r1][r2] += grid[r1][c1] + grid[r2][c2];
                            }
                        }
                    }
                }
            }
        }
        if(dp[0][0] == INT_MIN) return 0;
        return dp[0][0];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    // vector<vector<int>> grid = {{1, 1, -1}, {1, -1, 1}, {-1, 1, 1}};
    vector<vector<int>> grid = {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
    // vector<vector<int>> grid = {{1}};
    // vector<vector<int>> grid = 
    //    {{1,1,1,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,1},{1,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,1,1,1}};
    auto rst = s.cherryPickup(grid);
    return 0;
}

