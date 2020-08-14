/*
 * @lc app=leetcode.cn id=629 lang=cpp
 *
 * [629] K个逆序对数组
 */

/*
    dp[i][j] = 
        (dp[i-1][min(i(i-1)/2, j)] 
        + dp[i-1][j-1] + ... 
        + dp[i-1][max(0, j - i + 1)]).
    = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-i]
*/

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int kInversePairs(int n, int k) {
        int base = 1000000007;
        vector<int> dp(k+1, 0);
        dp[0] = 1;
        for(int i = 2; i <= n; ++i) {
            int top = min(i*(i-1)/2, k);
            vector<int> tmp(dp);
            for(int j = 1; j <= top; ++j) {
                dp[j] = (dp[j] + dp[j-1]) % base;
                if(j - i >= 0) {
                    dp[j] = (dp[j] - tmp[j - i] + base) % base;
                }
            }
        }
        return dp[k];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    int rst = s.kInversePairs(10, 5);
    return 0;
}

