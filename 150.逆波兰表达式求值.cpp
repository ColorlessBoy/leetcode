/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return 0;
        stack<int> s;
        for(auto &str: tokens) {
            if(str == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a / b);
            }
            else if(str == "*") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a * b);
            }
            else if(str == "+") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a + b);
            }
            else if(str == "-") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a - b);
            }
            else {
                s.push(stoi(str));
            }
        }
        return (s.empty())? 0: s.top();
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    return 0;
}

