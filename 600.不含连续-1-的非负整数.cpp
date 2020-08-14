/*
 * @lc app=leetcode.cn id=600 lang=cpp
 *
 * [600] 不含连续1的非负整数
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findIntegers(int num) {
        int dp[32] = {1, 2};
        for(int i = 2; i < 32; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return _findIntegers(num, dp);
    }
private:
    int _findIntegers(int num, int dp[32]) {
        if(num == 0) return 1;
        int base = 1, cnt = 1;
        while((base << 1) <= num) {
            base <<= 1;
            cnt++;
        }
        int next_num = num - base;
        if((base >> 1) & num) {
            next_num = (base >> 1) - 1;
        }
        return dp[cnt-1] + _findIntegers(next_num, dp);
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    auto rst = s.findIntegers(6);
    return 0;
}

