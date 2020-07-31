/*
 * @lc app=leetcode.cn id=937 lang=cpp
 *
 * [937] 重新排列日志文件
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> vs_str;
        vector<string> vs_num;
        for(auto &str: logs) {
            char ch = *(str.rbegin());
            if(ch >= '0' && ch <= '9') {
                vs_num.push_back(str);
            }
            else {
                vs_str.push_back(str);
            }
        }
        sort(vs_str.begin(), vs_str.end(),
        [](string &a, string &b) {
            string at = a.substr(a.find(' '));
            string bt = b.substr(b.find(' '));
            if(at == bt) {
                return a < b;
            }
            return at < bt;
        });
        vs_str.insert(vs_str.end(), vs_num.begin(), vs_num.end());
        return vs_str;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

