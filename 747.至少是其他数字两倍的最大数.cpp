/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

/*
 * Notes:
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) 
            return n - 1;
        int first = 0, second = -1;
        for(int i = 1; i < n; ++i) {
            if(nums[i] >= nums[first]) {
                second = first;
                first = i;
            }
            else if(second == -1 || nums[i] >= nums[second]) {
                second = i;
            }
        }
        if(nums[first] >= nums[second] * 2) {
            return first;
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

