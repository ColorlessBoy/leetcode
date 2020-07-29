/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> alphabeta(26, 0);
        for(auto &ch: s) {
            alphabeta[ch-'a']++;
        }
        for(auto &ch: t) {
            alphabeta[ch-'a']--;
        }
        for(int i = 0; i < 26; ++i) {
            if(alphabeta[i]) {
                return i + 'a';
            }
        }
        return 0;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    return 0;
}

