/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// 这个不是dp？
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if(A.empty()) return 0;
        int m = A.size(), n = A[0].size();
        for(int i = 1; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int tmp = A[i-1][j];
                if(j > 0) {
                    tmp = min(tmp, A[i-1][j-1]);
                }
                if(j < n - 1) {
                    tmp = min(tmp, A[i-1][j+1]);
                }
                A[i][j] += tmp;
            }
        }
        int rst = A[m-1][0];
        for(int j = 1; j < n; ++j) {
            rst = min(rst, A[m-1][j]);
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

