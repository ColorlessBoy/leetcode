/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
// 首先试试暴力回溯。
// 优化暴力回溯：对数组进行排序，从大的物体加起。
// 相同元素的处理。

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(auto &n: nums) {
            target += n;
        }
        if(target % 2) return false;
        target /= 2;

        sort(nums.begin(), nums.end(), greater<int>());
        // 从大到小排序，dfs深度可以大大降低。
        dfs(nums, 0, 0, target);
        return rst;
    }
private:
    bool rst;
    void dfs(vector<int>& nums, int idx, int cur_sum, int &target) {
        if(cur_sum > target || rst) {
            return;
        } 
        else if(cur_sum == target) {
            rst = true;
            return;
        }
        int n = nums.size();
        while(idx < n) {
            dfs(nums, idx + 1, cur_sum+nums[idx], target);
            do {
                idx++;
            } while(idx < n && nums[idx] == nums[idx-1]);
            // 跳到下一个不相同的字母。
        }
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    return 0;
}

