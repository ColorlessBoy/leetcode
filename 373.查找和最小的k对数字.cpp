/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 */

/* 
 * 非常特别的二分法查找。
 * 矩阵查找的典范。
 * 恶心点在于如何处理和相同的数对。
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.empty() || nums2.empty())
            return {};
        int rows = nums1.size(), cols = nums2.size();
        int left = nums1[0] + nums2[0], right = nums1[rows-1] + nums2[cols-1];
        while(left < right) {
            int mid = left + (right - left) / 2;
            int cnt = countSmallerPairs(nums1, nums2, mid);
            if(cnt <= k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        
        int rt = rows - 1, ct = 0;
        vector<vector<int>> rst;
        vector<vector<int>> rst2;
        while(rt >= 0) {
            while(ct < cols && nums1[rt] + nums2[ct] <= left) {
                ct++;
            }
            for(int i = 0; i < ct; ++i) {
                if(nums1[rt] + nums2[i] < left) {
                    rst.push_back({nums1[rt], nums2[i]});
                }
                else {
                    rst2.push_back({nums1[rt], nums2[i]});
                }
            }
            rt--;
        }
        for(int i = 0; i < rst2.size() && rst.size() < k; ++i) {
            rst.push_back(rst2[i]);
        }
        return rst;
    }
private:
    int countSmallerPairs(vector<int>& nums1, vector<int>& nums2, int target) {
        int rows = nums1.size(), cols = nums2.size();
        int rt = rows - 1, ct = 0;
        int cnt = 0;
        while(rt >= 0 && ct < cols) {
            while(ct < cols && nums1[rt] + nums2[ct] <= target) {
                ct++;
            }
            cnt += ct;
            rt--;
        }
        return cnt;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s = Solution();
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {1, 2, 3};
    int k = 10;
    s.kSmallestPairs(nums1, nums2, k);
    return 0;
}