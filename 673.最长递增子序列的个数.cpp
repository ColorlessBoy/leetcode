/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

/*
 * Note:
 * 1. 动态规划算法： O(n^2);
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<vector<pair<int, int>>> tables;
        for(auto &num: nums) {
            auto pos = distance(tables.begin(), 
                            lower_bound(tables.begin(), tables.end(), num,
                                [](vector<pair<int, int>>& a, const int &b) {
                                    return a.back().first < b;
                                })); // 首个不大于
            if(pos >= tables.size()) {
                tables.push_back(vector<pair<int,int>>());
            }

            // 计算以num结尾的最长递增子序列的个数。
            int tmp = 1; // 第一个元素
            if(pos > 0) {
                vector<pair<int, int>> &pre_vector = tables[pos-1];
                auto pos2 = distance(pre_vector.begin(), 
                                upper_bound(pre_vector.begin(), pre_vector.end(), num,
                                    [](const int &b, const pair<int, int>& a) {
                                        return b > a.first;
                                    })); // 首个小于。
                                //注意upper_bound的自定义比较函数的自变量，
                                // 和lower_bound的自定义比较函数的自变量相反，非常恶心。
                tmp = pre_vector.back().second;
                if(pos2 > 0)
                    tmp -= pre_vector[pos2-1].second;
            }
            int m = tables[pos].size();
            if(!tables[pos].empty()) {
                tmp += tables[pos].back().second;
            }
            tables[pos].push_back(make_pair(num, tmp));
        }
        return tables.back().back().second;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums = {10, 2, 5, 3, 7, 101, 4, 6, 5};
    auto rst = s.findNumberOfLIS(nums);
    return 0;
}

