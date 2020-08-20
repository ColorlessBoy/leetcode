/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 */

/*
Note: dfs + 记忆化搜索
*/

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(0, price, special, needs);
    }
private:
    int dfs(int idx, vector<int>& price, vector<vector<int>>& special, vector<int> needs) {
        int n = price.size();
        // 第一个结束状态：已经满足所有needs。
        bool flag = true;
        for(int i = 0; i < n; ++i) {
            if(needs[i]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            return 0;
        }
        // 第二个结束状态：大礼包已经考虑完毕。
        if(idx >= special.size()) {
            int rst = 0;
            for(int i = 0; i < n; ++i) {
                rst += price[i] * needs[i];
            }
            return rst;
        }

        // 购买的大礼包的类型作为节点
        int top = INT_MAX;
        for(int i = 0; i < n; ++i) {
            if(special[idx][i] == 0)
                continue;
            else 
                top = min(top, needs[i]/special[idx][i]);
        }
        vector<int> next_needs(needs);
        int rst = INT_MAX;
        for(int i = 0; i <= top; ++i) {
            rst = min(rst, special[idx][n] * i + dfs(idx + 1, price, special, next_needs));
            for(int j = 0; j < n; ++j) {
                next_needs[j] -= special[idx][j];
            }
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> prices = {2, 5};
    vector<vector<int>> specials = {{3, 0, 5}, {1, 2, 10}};
    vector<int> needs = {3, 2};
    auto rst = s.shoppingOffers(prices, specials, needs);
    return 0;
}

