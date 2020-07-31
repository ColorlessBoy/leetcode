/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> m;
        for(auto &d : dominoes) {
            if(d[0] < d[1]) {
                m[make_pair(d[0], d[1])]++;
            }
            else {
                m[make_pair(d[1], d[0])]++;
            }
        }
        int cnt = 0;
        for(auto &iter: m) {
            cnt += iter.second * (iter.second - 1) / 2;
        }
        return cnt;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

