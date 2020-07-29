/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.empty()) return 0;
        long long n = A.size(), sum = 0, F = 0;
        for(int i = 0; i < n; ++i) {
            sum += A[i];
            F += i * A[i];
        }
        long long rst = F;
        for(int i = 0; i < n - 1; ++i) {
            F = F - sum + n * A[i];
            rst = max(rst, F);
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    return 0;
}

