/*
 * @lc app=leetcode.cn id=916 lang=cpp
 *
 * [916] 单词子集
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> tableB(26, 0);
        for(auto &s: B) {
            vector<int> tab(26, 0);
            for(auto &ch: s) {
                tab[ch-'a']++;
            }
            for(int i = 0; i < 26; ++i) {
                tableB[i] = max(tableB[i], tab[i]);
            }
        }

        vector<string> rst;
        for(auto &s: A) {
            vector<int> tab(26, 0);
            for(auto &ch: s) {
                ++tab[ch-'a'];
            }
            bool flag = true;
            for(int i = 0; i < 26; ++i) {
                if(tab[i] < tableB[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) rst.push_back(s);
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

