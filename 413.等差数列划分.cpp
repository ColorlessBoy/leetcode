/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        for(int i = 0; i < n - 1; ++i) {
            A[i] -= A[i+1];
        }
        int cnt = 1, rst = 0;
        for(int i = 1; i < n - 1; ++i) {
            if(A[i] == A[i-1]) {
                cnt++;
            }
            else {
                rst += cnt * (cnt - 1) / 2;
                cnt = 1;
            }
        }
        rst += cnt * (cnt - 1) / 2;
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    return 0;
}

