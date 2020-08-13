/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        unsigned int n = num;
        string s;
        while(n) {
            s.push_back(getHexChar(n & 0xf));
            n >>= 4;
        }
        return string(s.rbegin(), s.rend());
    }
private:
    char getHexChar(int num) {
        if(num >= 0 && num < 10) {
            return num + '0';
        }
        else if(num >= 10 && num < 16) {
            return num - 10 + 'a';
        }
        return '0';
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    return 0;
}

