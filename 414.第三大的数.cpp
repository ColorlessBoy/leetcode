/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
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
    int thirdMax(vector<int>& nums) {
        if(nums.empty()) return 0;
        int table[3]={}, flag = 0;
        for(auto n: nums){
            int i;
            for(i = 0; i < flag; ++i) {
                if(n == table[i]){
                    break;
                } else if(n > table[i]){
                    swap(n, table[i]);
                }
            }
            if(i == flag && flag < 3) {
                table[flag++] = n;
            }
        }
        return (flag == 3)? table[2]: table[0];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums = {1, 2};
    auto rst = s.thirdMax(nums);
    return 0;
}

