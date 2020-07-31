/*
 * @lc app=leetcode.cn id=1072 lang=cpp
 *
 * [1072] 按列翻转得到最大值等行数
 */

// 特征值的味道,
// 和有限次翻转二叉树的题目一模一样。

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        unordered_map<string, int> table;
        int n = matrix.size(), m = matrix[0].size();
        int rst = 0;
        if(m == 0) return 0;
        for(auto &r: matrix) {
            string str;
            // 计算第r行的特征值
            int d = 1 ^ r[0];
            for(int j = 0; j < m; ++j) {
                str.push_back((r[j] ^ d) + '0');
            }
            rst = max(rst, ++table[str]);
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> matrix = {{1, 0}, {1, 1}};
    auto rst = s.maxEqualRowsAfterFlips(matrix);
    return 0;
}

