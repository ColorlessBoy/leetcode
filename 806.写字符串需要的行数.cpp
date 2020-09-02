/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
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
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lines = 0, width = 0, max_width = 100;
        for(auto &ch: S) {
            int word_width = widths[ch - 'a'];
            if(width + word_width > max_width) {
                lines++;
                width = word_width;
            }
            else {
                width += word_width;
            }
        }
        return {lines+1, width};
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

