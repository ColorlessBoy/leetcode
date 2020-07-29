/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alphabeta(26, 0);
        for(auto &ch: s) {
            alphabeta[ch - 'a']++;
        }
        for(int i = 0; i < s.size(); ++i) {
            if(alphabeta[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s();

    return 0;
}

