/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        // 这里的递归巧妙
        /*
            1 0 0 1
        +   0 1 0 1
        -----------
            1 1 0 0 (不进位的和)
        + 0 0 0 1   (进位的值)
        ----------- (递归，又是一个加法)          
        */
       // 递归结束点
       if(b == 0) return a;
       return (b == 0)? a : getSum(a ^ b, (unsigned)(a & b) << 1);
    }
};
// @lc code=end

