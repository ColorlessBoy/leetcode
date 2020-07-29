/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(auto &op: ops) {
            if(op == "C") {
                s.pop();
            }
            else if(op == "D") {
                s.push(s.top() * 2);
            }
            else if(op == "+") {
                int a = s.top(); s.pop();
                int b = s.top();
                s.push(a);
                s.push(a + b);
            }
            else {
                s.push(stoi(op));
            }
        }
        int rst = 0;
        while(!s.empty()) {
            rst += s.top();
            s.pop();
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

