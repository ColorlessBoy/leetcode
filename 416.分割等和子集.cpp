/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

/*
1. 优化暴力回溯：
    - 对数组进行排序，从大的物体加起。
    - 相同元素的处理。
2. 经典背包问题： 使用动态规划dp[V], V表示背包的容量。
*/

#include <bits/stdc++.h>
using namespace std;

// @lc code=start

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0; 
        for(auto &n: nums) {
            sum += n;
        }
        if(sum % 2) return false;

        int target = sum/2, size = nums.size();
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;

        for(int i = 0; i < size; ++i) {
            for(int j = target; j > 0; --j) {
                if(j >= nums[i]) {
                    dp[j] = max(dp[j], dp[j - nums[i]]);
                }
                if(dp[target] == 0)
                    return true;
            }
        }
        return false;
    }
};

// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums = {1, 5, 11, 5};
    auto rst = s.canPartition(nums);
    return 0;
}


/*
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
*/