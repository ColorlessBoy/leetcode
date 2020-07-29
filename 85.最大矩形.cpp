/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// 这道题和栈有什么联系呢?
// 不是动态规划吗？

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix[0].size(), rst = 0;
        vector<int> heights(n, 0);
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1') {
                    heights[j]++;
                }
                else {
                    heights[j] = 0;
                }
            }
            rst = max(rst, maxMatrix(heights));
        }
        return rst;
    }
private:
    int maxMatrix(vector<int>& heights) {
        if(heights.empty()) return 0;
        stack<int> s;
        heights.push_back(0);
        int n = heights.size(), rst = 0;
        for(int i = 0; i < n; ++i) {
            int hi = heights[i];
            while(!s.empty() && heights[s.top()] > hi) {
                int j = s.top(); s.pop();
                int distance = (s.empty())? i : i - s.top() - 1;
                rst = max(rst, distance * heights[j]);
            }
            s.push(i);
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<vector<char>> matrix = 
        {{'1', '0', '1', '0', '0'},
         {'1', '0', '1', '1', '1'},
         {'1', '1', '1', '1', '1'},
         {'1', '0', '0', '1', '0'}};
    int rst = s.maximalRectangle(matrix);
    return 0;
}

