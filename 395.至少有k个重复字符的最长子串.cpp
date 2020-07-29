/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 */

/*
 * 毫无思路。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if(n < k) return 0;
        vector<int> alphabeta(26, 0);
        for(auto &ch: s) {
            alphabeta[ch - 'a']++;
        }
        // 优化breakpoints
        vector<int> breakpoints;
        int prebreak = -1;
        bool flag = true; // 是否有break;
        for(int i = 0; i < n; ++i) {
            if(alphabeta[s[i] - 'a'] < k) {
                flag = false;
                if(i - prebreak - 1 >= k) {
                    if(breakpoints.empty())
                        breakpoints.push_back(prebreak);
                    breakpoints.push_back(i);
                }
                prebreak = i;
            }
        } 
        if(flag) return n;
        if(n - prebreak -1 >= k) {
            if(breakpoints.empty())
                breakpoints.push_back(prebreak);
            breakpoints.push_back(n);
        }
        int rst = 0;
        for(int i = 1; i < breakpoints.size(); ++i) {
            int start = breakpoints[i-1] + 1, end = breakpoints[i];
            rst = max(rst, longestSubstring(s.substr(start, end), k));
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string str = "bbaaacbd";
    int rst = s.longestSubstring(str, 3);
    return 0;
}

