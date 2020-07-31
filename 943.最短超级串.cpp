/*
 * @lc app=leetcode.cn id=943 lang=cpp
 *
 * [943] 最短超级串
 */

// 这个和栈有什么关系？
// 公共子串 + dfs?

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        if(A.empty()) return "";
        int n = A.size();
        if(n == 1) return A[0];

        vector<vector<int>> reward(n, vector<int>(n, -1));
        // 首先构造Reward Function.
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                reward[i][j] = getReward(A[i], A[j]);
                reward[j][i] = getReward(A[j], A[i]);
            }
        }

        //从数组的全排序（full permutation)里找reward最大的排序。
        int S = 1 << n;
        vector<vector<int>> dp(S, vector<int>(n, 0));
        vector<vector<pair<int, int>>> prev(S, vector<pair<int, int>>(n));
        for(int s = 1; s < S; ++s) {
            // 这里的关键是 s|(1<<j) 一定大于 s,所以s一定被遍历过，所以dp[s]是对的。
            for(int i = 0; i < n; ++i) {
                if(((s >> i) & 1) == 0) continue;
                for(int j = 0; j < n; ++j) {
                    if((s >> j) & 1) continue;
                    int sj = s | (1 << j);
                    if(dp[sj][j] <= dp[s][i] + reward[i][j]) {
                        dp[sj][j] = dp[s][i] + reward[i][j];
                        prev[sj][j] = make_pair(s, i);
                    }
                }
            }
        }

        // 构建字符串
        int end = 0;
        int s = S - 1;
        for(int i = 0; i < n; ++i) {
            if(dp[s][end] < dp[s][i])
                end = i;
        }
        string rst = A[end];
        for(int i = 0; i < n - 1; ++i) {
            auto p = prev[s][end];
            rst = A[p.second] + rst.substr(reward[p.second][end]);
            s = p.first;
            end = p.second;
        }
        return rst; 
    }
private:
    int getReward(string &t, string &p) {
        int idx_p = 0;
        vector<int> next = getNext(p);
        for(int i = 0, j = 0; i < t.size(); ++i) {
            while(idx_p >= 0 && t[i] != p[idx_p]) {
                idx_p = next[idx_p];
            }
            idx_p++;
        }
        return idx_p;
    }
    vector<int> getNext(string &s) {
        if(s.empty()) return {};
        int n = s.size();
        vector<int> next(n, -1);
        for(int i = 1; i < n; ++i) {
            int pre = next[i - 1];
            while(pre >= 0 && s[pre] != s[i]) {
                pre = next[pre];
            }
            next[i] = pre + 1;
        }
        return next;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<string> A = {"catg", "ctaagt","gcta","ttca","atgcatc"};
    // vector<string> A = {"gzst","ejtgs","gsgz","jtgsg"};
    // vector<string> A = {"ift","efd","dnete","tef","fdn"};
    auto rst = s.shortestSuperstring(A);
    return 0;
}

