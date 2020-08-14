/*
 * @lc app=leetcode.cn id=552 lang=cpp
 *
 * [552] 学生出勤记录 II
 */

/*
    这是一个排列组合问题吧。
    首先不考虑 A 状态。
    dp[记录长度][开头还能迟到几次]
    dp[i][2] = dp[i-1][1] (当前迟到)
             + dp[i-1][2] (当前不迟到)
    dp[i][1] = dp[i-1][0] (当前迟到)
             = dp[i-1][2] (当前不迟到)
    dp[i][0] = dp[i-1][2] (当前不迟到)
    现在考虑 A 状态。
    dp[记录长度][已经连续迟到几次][已经缺勤几次]
    dp[i][0][0] = dp[i-1][0][1] + dp[i-1][0][0] + dp[i-1][1][0]
    dp[i][1][0] = dp[i-1][0][1] + dp[i-1][0][0] + dp[i-1][2][0]
    dp[i][2][0] = dp[i-1][0][1] + dp[i-1][0][0]
    dp[i][0][1] = dp[i-1][0][1] + dp[i-1][1][1]
    dp[i][1][1] = dp[i-1][0][1] + dp[i-1][2][1]
    dp[i][2][1] = dp[i-1][0][1]
*/

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int checkRecord(int n) {
        array<int, 6> dp; dp.fill(1);
        array<int, 6> dp_next{1};
        int base = 1000000007;
        for(int i = 0; i < n; ++i) {
            dp_next[0] = ((dp[0] + dp[1]) % base + dp[3]) % base;
            dp_next[1] = ((dp[0] + dp[2]) % base + dp[3]) % base;
            dp_next[2] = (dp[0] + dp[3]) % base;
            dp_next[3] = (dp[3] + dp[4]) % base;
            dp_next[4] = (dp[3] + dp[5]) % base;
            dp_next[5] = dp[3] % base;
            swap(dp, dp_next);
        }
        return dp[0];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    int n = 1;
    auto rst = s.checkRecord(n);
    return 0;
}

