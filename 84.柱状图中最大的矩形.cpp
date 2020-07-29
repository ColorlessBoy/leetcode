/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return false;
        stack<int> s;
        heights.push_back(0);
        int n = heights.size(), max_area = 0;
        for(int current_i = 0; current_i < n; ++current_i) {
            int current_h = heights[current_i];
            while(!s.empty() && heights[s.top()] > current_h) {
                int top_i = s.top(); s.pop();
                int distance = (s.empty())? current_i: current_i-s.top()-1;
                int area = heights[top_i] * distance;
                max_area = max(max_area, area);
            }
            s.push(current_i);
        }
        return max_area;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> heights = {2, 1, 2};
    int rst = s.largestRectangleArea(heights);
    return 0;
}

