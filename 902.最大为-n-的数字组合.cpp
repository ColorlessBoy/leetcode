/*
 * @lc app=leetcode.cn id=902 lang=cpp
 *
 * [902] 最大为 N 的数字组合
 */

/*
 * Notes:
 * 1. 位数比n少的一定可以；
 * 2. 首位比n小的也可以；
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        // 准备
        vector<int> nums, digits_table(10, 0);
        while(n) {
            nums.push_back(n % 10);
            n /= 10;
        }
        for(auto &str: digits) {
            digits_table[str[0]-'0'] = 1;
        }
        for(int i = 2; i < 10; ++i) {
            digits_table[i] += digits_table[i-1];
        }

        // 开始
        int rst = 0;
        for(int i = nums.size() - 1; i >= 0; --i) {
            if(i > 0) {
                int tmp = ((nums[i] > 0)? digits_table[nums[i]-1]:0);
                rst += ((1 + tmp) * pow(digits_table[9], i));
            }
            else {
                rst += digits_table[nums[i]];
            }
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<string> digits = {"1", "3", "5", "7"};
    auto rst = s.atMostNGivenDigitSet(digits, 100);
    return 0;
}

