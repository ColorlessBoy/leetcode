/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

/*
 * Note:
 * 1. dp[i][j] 表示以 A[i] 和 B[j] 开头的子数组的最长公共子串。
 * 2. if A[i] == B[j]: dp[i][j] = 1 + dp[i+1][j+1];
 * 3. if A[i] != B[j]: dp[i][j] = 0;
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(A.size() < B.size()) {
            swap(A, B); // O(1)
        }
        int m = A.size(), n = B.size(), rst = 0;
        vector<int> dp(n + 1, 0);
        for(int i = m - 1; i >= 0; --i) {
            for(int j = 0; j < n; ++j) {
                if(A[i] == B[j]) {
                    dp[j] = 1 + dp[j+1];
                }
                else {
                    dp[j] = 0;
                }
                rst = max(rst, dp[j]);
            }
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    return 0;
}

