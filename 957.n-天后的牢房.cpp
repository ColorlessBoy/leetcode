/*
 * @lc app=leetcode.cn id=957 lang=cpp
 *
 * [957] N 天后的牢房
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if(N <= 0 || cells.empty()) return cells;
        int n = 0;
        for(int i = 0; i < 8; ++i) {
            n = (n << 1) + cells[i];
        }
        unordered_map<int, int> record;
        int T = 0;
        while(N > 0) {
            if(T == 0) {
                if(record.find(n) == record.end()) {
                    record[n] = N;
                }
                else {
                    T = record[n] - N;
                    N %= T;
                    if(N == 0) break;
                }
            }
            n = (~((n >> 1) ^ (n << 1))) & 0x7e;
            N--;
        }
        for(int i = 7; i >= 0; --i) {
            cells[i] = (n & 1);
            n >>= 1;
        }
        return cells;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> cells = {1, 0, 0, 0, 1, 0, 0, 1};
    auto rst = s.prisonAfterNDays(cells, 99);
    return 0;
}

