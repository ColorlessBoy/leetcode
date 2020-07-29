/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> alphbeta(26, 0);
        for(auto ch: magazine) {
            alphbeta[ch-'a']++;
        }
        for(auto ch: ransomNote) {
            if(--alphbeta[ch-'a'] < 0) {
                return false;
            }
        } 
        return true;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s();

    return 0;
}

