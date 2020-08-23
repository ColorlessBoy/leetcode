/*
 * @lc app=leetcode.cn id=730 lang=cpp
 *
 * [730] 统计不同回文子序列
 */
<<<<<<< HEAD

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
 * 4. 空间复杂度可以从 O(n^2) 优化到 O(n)，但是不够优雅。
 * 5. 初始状态非常微妙，长度等于１的数组一定是回文串，长度等于２的数组的回文串数量一定为２。
 */
=======
/*
 * Note:
 * 这个动态规划问题有点难, 暴力的话最高复杂度4^500，关键是我们要找到子问题。
 * /
>>>>>>> 66256af2306c958cc79c8137c20d2fa2ca15e19e

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int countPalindromicSubsequences(string S) {
<<<<<<< HEAD
        int n = S.size(), base = 1000000007;

        if(n <= 2) return n;

        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(4, -1)));
        for(int i = 0; i < n; ++i) {
            for(int state = 0; state < 4; ++state) {
                memo[i][i][state] = 0;
                if(i < n - 1)
                    memo[i][i+1][state] = 0;
            }
            memo[i][i][S[i]-'a'] = 1;
            if(i < n - 1) {
                memo[i][i+1][S[i]-'a']++;
                memo[i][i+1][S[i+1]-'a']++;
            }
        }

        for(int len = 3; len <= n; ++len) {
            for(int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                for(int state = 0; state < 4; ++state) {
                    if(S[i] != state + 'a')
                        memo[i][j][state] = memo[i+1][j][state];
                    else if(S[j] != state + 'a')
                        memo[i][j][state] = memo[i][j-1][state];
                    else {
                        memo[i][j][state] = 2;
                        for(int state2 = 0; state2 < 4; ++state2) {
                            memo[i][j][state] += memo[i+1][j-1][state2];
                            memo[i][j][state] %= base;
                        }
                    }
                }
            }
        }

        int rst = 0;

        for(int state = 0; state < 4; ++state) {
            rst += memo[0][n-1][state];
            rst %= base;
        }

        return rst;
=======

>>>>>>> 66256af2306c958cc79c8137c20d2fa2ca15e19e
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
<<<<<<< HEAD
    string S = "aaa";
    auto rst = s.countPalindromicSubsequences(S);
=======

>>>>>>> 66256af2306c958cc79c8137c20d2fa2ca15e19e
    return 0;
}

