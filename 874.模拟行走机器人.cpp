/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> s;
        for(auto &o: obstacles) {
           s.insert(make_pair(o[0], o[1]));
        }
        int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
        int x = 0, y = 0, head = 0, rst = 0;
        for(auto &c: commands) {
            if(c == -1) {
                head = (head + 3) % 4;
            }
            else if(c == -2) {
                head = (head + 1) % 4;
            }
            else {
                for(int i = 1; i <= c; ++i) {
                    int nx = x + dx[head];
                    int ny = y + dy[head];
                    if(s.find(make_pair(nx, ny)) != s.end()) {
                        break;
                    }
                    x = nx;
                    y = ny;
                }
                rst = max(rst, x * x + y * y);
            }
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    // vector<int> command = {4, -1, 3};
    // vector<vector<int>> obstacles = {};

    vector<int> command = {-2,-1,-2,3,7};
    vector<vector<int>> obstacles = {{1,-3},{2,-3},{4,0},{-2,5},{-5,2},{0,0},{4,-4},{-2,-5},{-1,-2},{0,2}};
    auto rst = s.robotSim(command, obstacles);
    return 0;
}

