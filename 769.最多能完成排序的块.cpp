/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

/*
 * Notes:
 * 1. arr的长度在 [1, 10] 之间，数字这么小肯定有猫腻。
 *    暴力的拆分也只有 2 ^ 9 种可能。但是显然有公共子问题。
 * 2. 前缀最大值： prev_max[i] = max(arr[0, ..., i]);
 * 3. 每次找 prev_max[i] 中， 首次不小于 arr[k] 的数字的下标。
 * 
 * 注意： 数字是 [0, 1, ..., N-1], 所以可以更简便
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int pre_max = -1, cnt = 0;
        for(int i = 0; i < arr.size(); ++i) {
            pre_max = max(pre_max, arr[i]);
            if(pre_max == i) {
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    //vector<int> arr = {0};
    vector<int> arr = {1, 0, 2, 3, 4};
    //vector<int> arr = {1, 4, 0, 2, 3, 5};
    auto rst = s.maxChunksToSorted(arr);
    return 0;
}

