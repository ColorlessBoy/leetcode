/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */

// dfs? 总是超时
// 动态规划？
// dfs从后往前搜索？

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n <= 1) return true;
        else if(n == 2) return stones[1] == 1;

        unordered_map<int, set<int>> m;
        for(auto &s: stones) {
            m[s] = set<int>();
        }

        m[0].insert(0);

        for(auto &s: stones) {
            for(auto &pk: m[s]) {
                for(int k = pk-1; k <= pk+1; ++k) {
                    if(k >= 1 && m.find(s + k) != m.end()) {
                        m[s + k].insert(k);
                    }
                }
            }
        }
        return !m[stones[n-1]].empty();
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    bool rst = s.canCross(stones);
    return 0;
}

