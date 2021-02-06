/*
 * @lc app=leetcode.cn id=923 lang=cpp
 *
 * [923] 三数之和的多种可能
 */

/*
 * Notes:
 * 背包问题：东西不能重复，选三个东西。可能有0。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        vector<vector<int>> cnt(3, vector<int>(target + 1, 0));
        int base = 1000000007;
        for(auto &a : arr) {
            for(int i = 2; i >= 0; --i) {
                for(int j = target; j >= 0; --j) {
                    if(i == 0) {
                        if(j == a) cnt[i][j] += 1;
                    } else {
                        if(j >= a) {
                            cnt[i][j] += cnt[i - 1][j - a];
                            cnt[i][j] %= base;
                        }
                    }
                }
            }
        }
        return cnt[2][target];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> A = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int target = 8;
    int rst = s.threeSumMulti(A, target);
    return 0;
}

