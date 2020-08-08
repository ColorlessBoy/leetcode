/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

/*
 * Note:
 * 哈希表太强了：
 *     要增加很多信息。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = -1;
        for(int i = 0 ; i < nums.size() ; ++i) {
            sum += nums[i];
            if(k != 0) sum %= k;
            if(mp.find(sum) != mp.end()) {
                if(i - mp[sum] > 1) {
                    return true;
                }
            }
            else {
                mp[sum] = i;
            }
        }
        return false;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

