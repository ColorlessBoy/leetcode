/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */

#include <bits/stdc++.h>
using namespace std;
// 数论知识：
// 1. 欧拉函数 phi(n): 小于n中与n互质的数。
//    phi(1337) = 1140.
// 2. 欧拉定理
//    A^{B} mod C = A^{B mod \phi(C) + \phi(C)} mod C.

// @lc code=start

class Solution {
public:
    int superPow(int a, vector<int>& b) {

        int base = 1337;
        int phi_base = 1140;
        int pow = 0;
        for(auto n: b) {
            pow = (pow * 10 + n % phi_base) % phi_base;
        }
        pow += phi_base;

        int rst = 1;
        a = a % base;
        for(int i = 0; i < pow; ++i) {
            rst = rst * a % base;
        }
        return rst;
    }
};
// @lc code=end

