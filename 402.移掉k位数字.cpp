/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        int len = num.size() - k;
        for(auto &digit: num) {
            while(k > 0 && !s.empty() && digit < s.top()) {
                s.pop();
                k--;
            }
            s.push(digit);
        }
        string rst;
        while(!s.empty() > 0) {
            rst.push_back(s.top());
            s.pop();
        }
        rst = string(rst.end()-len, rst.end());
        for(int i = rst.size()-1; i >= 0; --i) {
            if(rst[i] == '0')
                rst.pop_back();
            else
                break;
        }
        reverse(rst.begin(), rst.end());
        return rst.empty() ? "0" : rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

