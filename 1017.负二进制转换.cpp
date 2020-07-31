/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 *
 * [1017] 负二进制转换
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string baseNeg2(int N) {
        if(N == 0) return "0";
        string rst;
        int idx = 0;
        while(N > 0) {
            rst.push_back((N & 1) + '0');
            if(idx % 2) N += 1;
            N >>= 1;
            idx++;
        }
        return string(rst.rbegin(), rst.rend());
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    auto rst = s.baseNeg2(4);
    return 0;
}

