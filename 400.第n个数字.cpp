/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第N个数字
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        //查找n在的位置是几位数
        int nOfDigits = 1, i = n, base = 1;
        while(nOfDigits < 9 && i > 9 * base * nOfDigits) {
            i -= 9 * base * nOfDigits;
            nOfDigits++;
            base *= 10;
        }

        //查找n是第几个数
        int num = base + (i - 1) / nOfDigits;

        //查找n是第几个数位
        i = nOfDigits - (i - 1) % nOfDigits;
        int rst = 0;
        while(i > 0) {
            rst = num % 10;
            num /= 10;
            i--;
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    int rst = s.findNthDigit(1000000000);
    return 0;
}

