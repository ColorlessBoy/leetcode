/*
 * @lc app=leetcode.cn id=446 lang=cpp
 *
 * [446] 等差数列划分 II - 子序列
 */

/*
 * 肯定要从小到大对A进行排序。
 * 接着使用动态规划：
 * dp[i][delta] 表示以 A[i] 结尾， 公差为 delta 的等差数列的个数。
 * 1. 首先简化问题，我们引入弱等差数列：等差数列的长度可以等于2。
 * 2. 那么状态转移方程为：
 *    dp[i][A[i] - A[j]] = 1 + dp[j][A[i] - A[j]]; // 其中 1 就是增加的弱等差数列。
 * 3. 神奇的来了，在每一步的状态转移中 dp[j][A[i] - A[j]] 就是新形成的真等差数列的个数。
*/

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        #define LL long long
        int n = A.size();
        if(n < 3) return 0;

        vector<unordered_map<LL, int>> dp(n);
        int rst = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                LL delta = (LL)A[i] - (LL)A[j];
                dp[i][delta] += 1;
                if(dp[j].find(delta) != dp[j].end()) {
                    dp[i][delta] += dp[j][delta];
                    rst += dp[j][delta];
                }
            }
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums = {2, 2, 3, 4};
    auto rst = s.numberOfArithmeticSlices(nums);
    return 0;
}

