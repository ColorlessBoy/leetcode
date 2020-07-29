/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> rst(nums.begin(), nums.end());
        for(int i = nums.size(); i > 0; --i) {
            swap(rst[rand() % i], rst[i-1]);
        }
        return rst;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

int main(int argc, char **argv) {
    Solution s();

    return 0;
}

