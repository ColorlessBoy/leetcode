/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        if(s.empty()) return "";
        stack<int> si;
        stack<string> ss;
        string str;
        bool isNum = false;
        for(auto &ch: s) {
            if(!isNum) {
                //文字模式
                if(ch >= '0' && ch <= '9') {
                    isNum = true;
                    insert(str, si, ss);
                    str.clear();
                }
                else if(ch == ']') {
                    //出栈, 默认不会出现问题
                    insert(str, si, ss);
                    int sit = si.top(); si.pop();
                    str = ss.top(); ss.pop();
                    string tmp;
                    while(sit--) {
                        tmp += str;
                    }
                    insert(tmp, si, ss);
                    str.clear();
                }
                else {
                    str.push_back(ch);
                }
            }
            if(isNum) {
                //数字模式
                if(ch == '[') {
                    //数字结束
                    si.push(stoi(str));
                    ss.push("");
                    str.clear();
                    isNum = false;
                }
                else {
                    //默认字符串是合乎标准的
                    str.push_back(ch);
                }
            }
        }
        return (ss.empty())? str : ss.top() + str;
    }
private:
    void insert(string str, stack<int> &si, stack<string> &ss) {
        if(str.empty())
            return;
        while(!si.empty() && si.top() == 0) {
            str = ss.top() + str;
            si.pop();
            ss.pop();
        }
        if(ss.empty()) {
            si.push(0);
            ss.push(str);
        }
        else {
            str = ss.top() + str;
            ss.pop();
            ss.push(str);
        }
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    // string str = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    string str = "leetcode";
    string rst = s.decodeString(str);
    return 0;
}