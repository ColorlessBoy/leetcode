/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        rst.clear();
        top = n;
        for(int i = 1; i <= 9; ++i) {
            dfs(i);
        }
        return rst;
    }
private:
    vector<int> rst;
    int top;
    void dfs(int num) {
        if(num > top)
            return;
        rst.push_back(num);
        for(int i = 0; i <= 9; ++i) {
            dfs(num*10+i);
        }
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s();

    return 0;
}

