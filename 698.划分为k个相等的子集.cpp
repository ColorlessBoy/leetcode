/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

/*
 * Note:
 * 这道题目的关键是需要证明一件事情：
 * 为什么可以贪心地dfs搜索? (每次dfs搜索获得一组和为 sum / k 的子数组。)
 * 这个贪心法的关键似乎是从大到小搜索数字。
 * 因为如果 nums = [1, 1, 1, 1, 3, 3, 3, 3], 先贪心地找到 [1, 1, 1, 1] 那么接下来就没办法做了。
 * 但是如果 nums = [3, 3, 3, 3, 1, 1, 1, 1], 那么贪心法没什么问题。
 * 
 * 1. 穷举法。
 * 上面我想错了，这里不是贪心地搜索，而是暴力地搜索。也就是说： 
 * 如果先找到了 [1, 1, 1, 1] 结果发现剩下的没有办法分解了，我们就继续暴力检索[1, 1, 1, 3]等等。
 * 
 * 
 * 那么暴力法如何通过记忆化的dfs来减少探索呢？
 * 我们注意到 len(Nums) <= 16 所以我们可以用一个integer表示数组被访问的状态。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // 处理一些简单事件。
        int n = nums.size();
        if(n < k) return false;

        int sum = 0;
        for(auto &n: nums) {
            sum += n;
        }
        if(sum % k) return false;
        volumn = sum / k;
        for(auto &n: nums) {
            if(n > volumn) return false;
        }

        // 准备暴力检索。
        visited = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(0, volumn, nums);
    }
private:
    int visited;
    int volumn;
    bool dfs(int root, int target, vector<int>& nums) {
        if(((visited >> root) & 1) || nums[root] > target)
            return false;

        int n = nums.size();
        bool rst = false;

        visited |= (1 << root);
        target -= nums[root];
        if(target == 0) {
            if((visited+1)>>n)
                rst = true;
            else {
                int next_root = 0;
                for(; next_root < n; ++next_root) {
                    if(((visited>>next_root)&1) == 0)
                        break;
                }
                rst = dfs(next_root, volumn, nums);
            }
        }
        else {
            for(int i = 0; i < n; ++i) {
                if(dfs(i, target, nums)) {
                    rst = true;
                    break;
                }
            }
        }
        visited ^= (1 << root);
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    auto rst = s.canPartitionKSubsets(nums, k);
    return 0;
}

