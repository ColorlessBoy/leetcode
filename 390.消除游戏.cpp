/*
 * @lc app=leetcode.cn id=390 lang=cpp
 *
 * [390] 消除游戏
 */
/*
 * 这个应该是个有意思的递归算法。
 * 这个题目的变种很多。
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int lastRemaining(int n, int k) {
        return (n == 1)? 1 : (k - 1 + lastRemaining(n - 1, k)) % n + 1;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    int rst = s.lastRemaining(8, 3);
    return 0;
}

