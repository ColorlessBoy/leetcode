/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 */
// 暴力法: O(N!)
// 回朔法: ???
// 回朔法是什么东西？和暴力法有什么关系？

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int countArrangement(int N) {
        cnt = 0;
        end = (1 << (N + 1)) - 1;
        dfs(N, 1, 1);
        return cnt;
    }
private:
    int cnt;
    int end;
    void dfs(int N, int idx, int used) {
        if(idx > N) {
            cnt++;
            return;
        }
        for(int i = 1; i <= N; ++i) {
            if((used >> i & 1) == 0
                && (i % idx == 0 || idx % i == 0)) {
                dfs(N, idx+1, used | (1 << i));
            }
        }
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    auto rst = s.countArrangement(2);
    return 0;
}

