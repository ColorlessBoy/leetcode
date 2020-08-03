/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// 方法1：动态规划
// 方法2：二分查找

#include <bits/stdc++.h>
using namespace std;

// @lc code=start

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for(auto &n: nums) {
            right += n;
            left = max(left, (long long)n);
        }
        while(left <= right) {
            long long mid = left + (right - left) / 2;
            if(count(nums, mid) > m) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left;
    }
private:
    int count(vector<int>& nums, int target) {
        long long sum = 0;
        int cnt = 1;
        for(auto &n: nums) {
            sum += n;
            if(sum > target) {
                sum = n;
                cnt++;
            }
        }
        return cnt;
    }
};

// class Solution {
// public:
//     int splitArray(vector<int>& nums, int m) {
//         int n = nums.size();
// 
//         vector<int> dp(n, INT_MAX);
//         vector<int> pre_dp(n, INT_MAX);
// 
//         //分成一份
//         int sum = 0;
//         for(int i = 0; i <= n - m; ++i) {
//             sum += nums[i];
//             pre_dp[i] = sum;
//         }
//         
//         //分成多份
//         for(int i = 2; i <= m; ++i) {
//             //要求分为i份
//             for(int j = n - 1; j >= i - 1; --j) {
//                 //要求把数组 nums[0..j] 分为 i 份。
//                 //求dp[i][j] = min_k { max(dp[i-1][k], sum(nums[k+1, j]))}.
//                 sum = nums[j];
//                 for(int k = j - 1; k >= 0; --k) {
//                     if(sum >= dp[j]) {
//                         // 因为非负整数，我们可以提前结束。
//                         break;
//                     }
//                     dp[j] = min(dp[j], max(pre_dp[k], sum));
//                     sum += nums[k];
//                 }
//                 if(i == m && j == n - 1) break;
//             }
//             swap(dp, pre_dp);
//         }
//         return pre_dp[n-1];
//     }
// };
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums = {1, INT_MAX};
    auto rst = s.splitArray(nums, 2);
    return 0;
}

