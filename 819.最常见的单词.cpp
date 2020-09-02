/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */

/*
 * Notes:
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banned_set(banned.begin(), banned.end());
        unordered_map<string, int> table;
        for(auto &ch: paragraph) {
            if(ch >= 'A' && ch <= 'Z') {
                ch = (ch - 'A' + 'a');
            }
            else if(ch >= 'a' && ch <= 'z') {
                continue;
            }
            else {
                ch = ' ';
            }
        }
        istringstream is(paragraph);
        string word;
        while(is >> word) {
            if(banned_set.find(word) == banned_set.end()) {
                table[word]++;
            }
        }

        int max_cnt = 0;
        for(auto &iter: table) {
            if(iter.second > max_cnt) {
                max_cnt = iter.second;
                word = iter.first;
            }
        }
        return word;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string str = "Bob. hIt, baLl";
    vector<string> banned = {"bob", "hit"};
    auto rst = s.mostCommonWord(str, banned);
    return 0;
}

