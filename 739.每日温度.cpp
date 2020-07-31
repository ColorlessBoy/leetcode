/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.empty()) return {};
        int n = T.size();
        stack<int> s; //单调递减栈
        vector<int> vi(n, 0);
        for(int i = 0; i < n; ++i) {
            while(!s.empty() && T[i] > T[s.top()]) {
                vi[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return vi;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

