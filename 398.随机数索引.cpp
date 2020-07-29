/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<int> nums;
    int size;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        size = nums.size();
    }
    
    int pick(int target) {
        int cnt = 0, idx = -1;
        for(int i = 0; i < size; ++i) {
            if(nums[i] == target) {
                cnt++;
                if(rand() % cnt == 0) {
                    idx = i;
                }
            }
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    return 0;
}

