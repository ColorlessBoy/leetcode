/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(answers.empty()) return 0;
        map<int, int> m;
        for(auto &n: answers) {
            m[n]++;
        }
        int cnt = 0;
        for(auto &iter: m) {
            int a = iter.first + 1;
            int b = iter.second;
            cnt += (b + a - 1) / a * a;
        }
        return cnt;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> answers = {1, 0, 1, 0, 0};
    int rst = s.numRabbits(answers);
    return 0;
}

