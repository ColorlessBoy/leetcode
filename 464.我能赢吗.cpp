/*
 * @lc app=leetcode.cn id=464 lang=cpp
 *
 * [464] 我能赢吗
 */

/*
 * Note:
 * dfs + memo
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        m = maxChoosableInteger, d = desiredTotal;
        if(m >= d) 
            return true;
        else if(m <= 0) 
            return desiredTotal == 0;
        else if(m * (m + 1) / 2 < desiredTotal) 
            return false;

        dp = vector<unordered_map<int, bool>>(d + 1);
        mask = (1 << maxChoosableInteger) - 1;
        return dfs(d, mask);
    }
private:
    vector<unordered_map<int, bool>> dp;
    int mask, m, d;
    bool dfs(int idx, int state) {
        if(idx <= 0) return false; //提前终止
        else if(dp[idx].find(state) != dp[idx].end()) {
            return dp[idx][state];
        }
        else {
            dp[idx][state] = false;
            for(int i = 0; i < m; ++i) {
                if((state >> i) & 1) {
                    bool tmp = dfs(idx - i - 1, state ^ (1 << i));
                    if(tmp == false) {
                        dp[idx][state] = true;
                        break;
                    }
                }
            }
        }
        return dp[idx][state];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    auto rst = s.canIWin(10, 40);
    return 0;
}

