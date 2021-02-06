/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

/*
 * Notes:
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if(A.empty()) return {};
        int m = A.size(), n = A[0].size();
        vector<vector<int>> B(n, vector<int>(m));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                B[j][i] = A[i][j];
            }
        }
        return B;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    return 0;
}

