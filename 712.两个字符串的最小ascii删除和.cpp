/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

/*
 * Note:
 * 1. dp[i][j] 表示 s1[i...] 与 s2[j...] 删除的最小和；
 * 2. s1[i] == s2[j] 时， 
 *    dp[i][j] = dp[i+1][j+1]；
 *    //需要保留 dp[i+1][j+1]
 * 3. s1[i] != s2[j] 时， 
 *    dp[i][j] = min(s1[i] + dp[i+1][j],
 *                   s2[j] + dp[i][j+1]);
 *    // 需要先计算 dp[i][j+1]
 * 4. 我们注意到了，如果只用一维dp来保存信息，会出现一个矛盾。
 *    这里我们使用一个变量来保存 dp[i+1][j+1]。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        if(s1.size() < s2.size())
            swap(s1, s2); // O(1)
        int m = s1.size(), n = s2.size();
        vector<int> dp(n+1, INT_MAX);
        for(int i = m; i >= 0; --i) {
            int pre_i1_j1; // 使用变量保存 dp[i+1][j+1]
            for(int j = n; j >= 0; --j) {
                int tmp = dp[j]; // 先保存 dp[i+1][j];
                if(i == m && j == n) {
                    dp[j] = 0;
                }
                else if(i == m) {
                    dp[j] = s2[j] + dp[j+1];
                }
                else if(j == n) {
                    dp[j] += s1[i];
                }
                else if(s1[i] == s2[j]) {
                    dp[j] = pre_i1_j1;
                }
                else {
                    dp[j] = min(s1[i] + dp[j], s2[j] + dp[j+1]);
                }
                pre_i1_j1 = tmp;
            }
        }
        return dp[0];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string s1 = "sea", s2 = "eat";
    auto rst = s.minimumDeleteSum(s1, s2);    
    return 0;
}

