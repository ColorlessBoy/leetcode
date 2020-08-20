/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

/*
 * Note:
 * 行程安排题，可以用贪心法。
 * 1. 首先以数对的第二个数字为准，排序；
 * 2. 每次选择结束最早的数对，把冲突数对全删掉。
 * 难点在于如何证明。
 * 1. 这个算法选出来的序列不冲突，最长的序列不短于这个算法求出的序列；
 * 2. 如果存在比这个算法选出来的序列长的序列，那么会出现矛盾：
 *    - 这个算法选出来的序列为 [a1, a2, ..., an];
 *    - 最长的序列为 [b1, b2, ..., bm]; (m > n)
 *    - 首先， a1 结尾不晚于 b1, 又可以推出 a2 结尾不晚于 b2, 以此类推。
 *    - 其次， b(n+1) 一定可以接到 a 序列后面，也就是说算法不会结束。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end(),
        [&](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> cur_pair = pairs[0];
        int cnt = 1;
        for(auto &pair: pairs) {
            if(pair[0] <= cur_pair[1])
                continue;
            cur_pair = pair;
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

