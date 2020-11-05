/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

/*
 * Notes:
 * 统计;
 * 偶数个数的字母一定可以当做回文串的一部分;
 * 奇数个数的字母需要取整,最后的结果加一。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        int table[53] = {};
        for(auto &ch: s) {
            table[encoder(ch)]++;
        }
        int rst = 0, hasOdd = 0;
        for(int i = 0; i < 52; ++i) {
            if(table[i] % 2) {
                hasOdd = 1;
            }
            rst += table[i] / 2;
        }
        return rst * 2 + hasOdd;
    }
private:
    int encoder(char ch) {
        if(ch >= 'A' && ch <= 'Z') {
            return ch - 'A';
        }
        else if(ch >= 'a' && ch <= 'z') {
            return ch - 'a' + 26;
        }
        return 52;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string str = "abccccdd";
    auto rst = s.longestPalindrome(str);
    return 0;
}

