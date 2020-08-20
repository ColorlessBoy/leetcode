/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

/*
 * Note:
 * 1. 肯定有解，开头复制，然后不停地粘贴，所以最多操作n次；
 * 2. dp[i] 表示打印 i 个 'A' 的最少操作次数。
 * 3. 设 j 满足 i % j == 0, 则有 dp[i] = min(dp[i], dp[j] + (i / j));
 * 4. 递归版的动态规划。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        dp.clear();
        dp = vector<int>(n + 1, INT_MAX);
        dp[1] = 0;
        return dfs(n);
    }
private:
    vector<int> dp;
    int dfs(int idx) {
        if(idx <= 0) return INT_MAX;
        if(dp[idx] < INT_MAX) return dp[idx];
        for(int j = 1; j <= idx / 2; ++j) {
            if(idx % j == 0) {
                dp[idx] = min(dp[idx], (idx / j) + dfs(j));
            }
        }
        return dp[idx];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    auto rst = s.minSteps(3);
    return 0;
}

