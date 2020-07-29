/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// 这个又和堆有什么关系呢？


#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(n < m) return {};
        stack<int> s;
        unordered_map<int, int> next_max; // 单调递减栈

        // 单调栈求next_max
        for(auto num: nums2) {
            while(!s.empty() && s.top() < num) {
                next_max[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        while(!s.empty()) {
            next_max[s.top()] = -1;
            s.pop();
        }

        vector<int> rst;
        for(auto &num: nums1) {
            rst.push_back(next_max[num]);
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    auto rst = s.nextGreaterElement(nums1, nums2);
    retu
}

