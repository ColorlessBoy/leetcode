/*
 * @lc app=leetcode.cn id=730 lang=cpp
 *
 * [730] 统计不同回文子序列
 */

/*
 * Notes:
 * 这道题看起来似乎是不可能完成的事情，我根据参考答案，来整理一个思路。
 * 1. dp[i][j][state]: state in ['a', 'b', 'c', 'd']
 *    表示 S[i...j] 子串中 
 *    state*state (a*a 、b*b、c*c 、d*d, 星号表示正则表达式的通配符) 形式的回文序列个数；
 * 2. 一个很重要的结论：
 *    这里我们只需要选择 S[i...j] 中 第一个和最后一个 state 字母所在的位置 [m, n] 
 *    作为我们回文串的开头和结尾的元素即可， 
 *    因为选 S[m+1, n-1] 之间的 state 作为我们回文串的开头或结尾的回文串一定被上面的字符串包含。
 *    所以我们得到了三个非常重要的状态转移方程：
 *    if(S[i] != state) dp[i][j][state] = dp[i+1][j][state];
 *    if(S[j] != state) dp[i][j][state] = dp[i][j-1][state];
 *    if(S[i] == state && S[j] == state)
 *      dp[i][j][state] = 2 + dp[i+1][j-1]['a'] + dp[i+1][j-1]['b'] 
 *                      + dp[i+1][j-1]['c'] + dp[i+1][j-1]['d'];
 * 3. 并且我们可以保证找出的回文序列一定不相同。
 * 4. 空间复杂度可以从 O(n^2) 优化到 O(n):
 *    i从大到小遍历， j从小到大遍历
 * 5. 初始状态非常微妙，长度等于１的数组一定是回文串，长度等于２的数组的回文串数量一定为２。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.size(), base = 1000000007;

        if(n <= 2) return n;

        vector<vector<int>> dp(n, vector<int>(4, 0));
        for(int i = n - 1; i >= 0; --i) {
            vector<int> pre_dp(dp[i]);
            dp[i][S[i]-'a'] = 1;
            for(int j = i + 1; j < n; ++j) {
                vector<int> tmp(dp[j]);
                for(int state = 0; state < 4; ++state) {
                    if(S[i] != state + 'a') {
                        continue;
                    }
                    else if(S[j] != state + 'a') {
                        dp[j][state] = dp[j-1][state];
                    }
                    else {
                        dp[j][state] = 2;
                        for(int state2 = 0; state2 < 4; ++state2) {
                            dp[j][state] += pre_dp[state2];
                            dp[j][state] %= base;
                        }
                    }
                }
                pre_dp = tmp;
            }
        }

        int rst = 0;
        for(int state = 0; state < 4; ++state) {
            rst += dp[n-1][state];
            rst %= base;
        }

        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string S = "aaa";
    auto rst = s.countPalindromicSubsequences(S);
    return 0;
}

