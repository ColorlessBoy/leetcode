/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

/*
 * Note:
 * 二维背包问题：
 * 1. 每样物品体积(0的个数）， 重量（1的个数），奖励均为1。
 * 2. 背包最大体积 m, 最大载重 n, 求最大奖励。
 * 3. for i in goods_num:
 *      dp[m][n][i] = max(dp[m][n][i], dp[m-good[i][0]][n - good[i][1]]+1);
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        vector<pair<int, int>> goods;
        for(auto &str: strs) {
            int volumn = 0, weight = 0;
            for(auto &ch: str) {
                if(ch == '0') volumn++;
                else weight++;
            }
            goods.push_back(make_pair(volumn, weight));
        }
        for(auto &good: goods) {
            for(int i = m; i >= 0; --i) {
                for(int j = n; j >= 0; --j) {
                    if(i >= good.first && j >= good.second) {
                        dp[i][j] = max(dp[i][j], 
                            dp[i - good.first][j - good.second]+1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<string> vs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    auto rst = s.findMaxForm(vs, m, n);
    return 0;
}

