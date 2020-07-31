/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        int n = text.size();
        bool pre_first = false, pre_second = false;
        for(int i = 0; i < n;) {
            int next = text.find(' ', i);
            if(next == -1) next = n;
            string word = text.substr(i, next - i);
            i = 1 + next;

            if(pre_second) {
                words.push_back(word);
            }
            if(pre_first && word == second) {
                pre_second = true;
            }
            else {
                pre_second = false;
            }
            if(word == first) {
                pre_first = true;
            }
            else {
                pre_first = false;
            }
        }
        return words;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string text = "alice is a good girl she is a good student";
    string first = "a";
    string second = "good";
    auto rst = s.findOcurrences(text, first, second);
    return 0;
}

