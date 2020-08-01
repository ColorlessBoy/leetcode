/*
 * @lc app=leetcode.cn id=691 lang=cpp
 *
 * [691] 贴纸拼词
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        if(stickers.empty()) return false;
        if(target.empty()) return true;

        int n = stickers.size();
        int m = target.size();

        // mask的思想
        sort(target.begin(), target.end());
        //相同字母连在一起。
        vector<int> target_mask(26, 0);
        for(int i = 0; i < m; ++i) {
            target_mask[target[i] - 'a'] |= (1 << i);
        }

        // BFS
        int end = (1 << m) - 1;
        queue<int> q({0});
        vector<int> dp(1 << m, -1);
        dp[0] = 0;
        while(!q.empty()) {
            int mask = q.front(); q.pop();
            for(int i = 0; i < n; ++i) {
                int tmp = mask;
                for(auto &ch: stickers[i]) {
                    int tmp2 = target_mask[ch - 'a'];
                    if(tmp2 != 0) {
                        //字母在target中出现
                        tmp |= (tmp + (tmp2 & (-tmp2))) & tmp2;
                    }
                }
                if(dp[tmp] == -1) {
                    dp[tmp] = dp[mask] + 1;
                    q.push(tmp);
                }
                if(tmp == end) {
                    break;
                }
            }
            if(dp[end] != -1) break;
        }
        return dp[end];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<string> stickers = {"with", "example", "science"};
    string target = "thehat";
    auto rst = s.minStickers(stickers, target);
    return 0;
}

