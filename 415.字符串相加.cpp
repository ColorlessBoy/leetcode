/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

/*
 * Notes:
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string rst;
        int c = 0;
        for(int i = 0; i < num1.size() || i < num2.size(); ++i) {
            int n1 = (i < num1.size())? num1[i] - '0': 0;
            int n2 = (i < num2.size())? num2[i] - '0': 0;
            int tmp = n1 + n2 + c; 
            rst.push_back(tmp%10+'0');
            c = tmp / 10;
        }

        if(c != 0)
            rst.push_back('1');
        reverse(rst.begin(), rst.end());
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string num1 = "9", num2 = "99";
    auto rst = s.addStrings(num1, num2);
    return 0;
}

