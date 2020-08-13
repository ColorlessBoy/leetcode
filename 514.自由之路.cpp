/*
 * @lc app=leetcode.cn id=514 lang=cpp
 *
 * [514] 自由之路
 */

/*
 * Note:
 * 难点：ring 可能有多种方法拼出 key, 要找出最近的那个。
 * 最值问题能转化为动态规划。
 * 那么动态规划数组应该是什么呢？
 * m = ring.size(), n = key.size()
 * dp[i][j]: 
 *   - ring[i] 对应 12:00 位置上的数字，也就是ring的状态;
 *   - key[j...n] 字符串；
 *   - dp[i][j] 表示 ring[i] 状态下拼出 key[j...n-1] 的最小动作。
 * 状态转移方程：
 *   for k in [0, m-1]
 *     if(ring[k] == ring[j])
 *       dp[i][j] = min(dp[i][j], dist(i, k) + dp[k][j+1]);
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size(), n = key.size();
        vector<int> dp_pre(m, 0);
        vector<int> dp(m, INT_MAX);
        for(int j = n - 1; j >= 0; --j) {
            for(int i = 0; i < m; ++i) {
                for(int k = 0; k < m; ++k) {
                    if(ring[k] == key[j]) {
                        dp[i] = min(dp[i], 
                            1 + dist(i, k, m) + dp_pre[k]);
                    }
                }
                if(j == 0 && i == 0)
                    break;
            }
            swap(dp, dp_pre);
            dp = vector<int>(m, INT_MAX);
        }
        return dp_pre[0];
    }
private:
    int dist(int &i, int &j, int &m) {
        int a = (i - j + m) % m;
        return min(a, m - a);
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string ring = "godding";
    string key = "gd";
    auto rst = s.findRotateSteps(ring, key);
    return 0;
}

