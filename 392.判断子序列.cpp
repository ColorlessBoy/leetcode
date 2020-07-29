/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0, n = t.size();
        for(auto &ch: s) {
            while(idx < n && t[idx] != ch) {
                ++idx;
            }
            if(idx >= n) return false;
            ++idx;
        }
        return true;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    return 0;
}

