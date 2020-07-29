/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto &ch: s) {
            if(ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
            }
            else if(stk.empty()) {
                return false;
            }
            else if(ch == ')' && stk.top() == '('
            || ch == ']' && stk.top() == '['
            || ch == '}' && stk.top() == '{') {
                stk.pop();
            }
            else {
                return false;
            }
        }
        return stk.empty();
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    bool rst = s.isValid("(])");
    return 0;
}

