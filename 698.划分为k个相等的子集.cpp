/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

/*
 * Note:
 * 这道题目的关键是需要证明一件事情：
 * 为什么可以贪心地dfs搜索? (每次dfs搜索获得一组和为 sum / k 的子数组。)
 * 这个贪心法的关键似乎是从大到小搜索数字。
 * 因为如果 nums = [1, 1, 1, 1, 3, 3, 3, 3], 先贪心地找到 [1, 1, 1, 1] 那么接下来就没办法做了。
 * 但是如果 nums = [3, 3, 3, 3, 1, 1, 1, 1], 那么贪心法没什么问题。
 * 证明：
 * nums 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return false;

        int sum = 0;
        for(auto &n: nums) {
            sum += n;
        }
        if(sum % k) return false;
        int volumn = sum / k;
        for(auto &n: nums) {
            if(n > volumn) return false;
        }        
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

