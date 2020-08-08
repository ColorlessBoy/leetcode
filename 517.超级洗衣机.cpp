/*
 * @lc app=leetcode.cn id=517 lang=cpp
 *
 * [517] 超级洗衣机
 */

/*
 * Note:
 * 这道题属于贪心法，难点在如何证明。
 * 0. 数组 int nums[n].
 * 1. 首先求和判断是否可以均分衣服, 平均值记为avg;
 * 2. 我们先求结果的下界：
 *      定义 deltas[n] = (nums[0]-avg, nums[1]-avg, ..., nums[n]-avg);
 *      定义 slices[i] = deltas[0] + ... + deltas[i] 表示 nums[i] 与 nums[i+1] 之间的截面；
 *      那么至少要移动衣服的次数是： a = max_i |slice[i]|。
 *      另一方面，对于每一台机器，每次只能输出一件衣服，所以至少要移动的衣服次数是: b = max_i deltas[i]。
 *      综上，我们得到了一个最少需要移动的衣服次数： max {a, b}。
 * 3. 我们要构造出一种移动衣服的方式，移动次数是 max{a, b}。
 *      只要证明，任何情况下，一定存在移动衣服的方案满足： a - 1 或者 b - 1。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        long long sum = 0, n = machines.size();
        for(auto &m: machines) {
            sum += m;
        }
        if(sum % n) return -1;
        int rst = 0, presum = 0, avg = sum / n;
        for(auto &m: machines) {
            presum += m - avg;
            rst = max(rst, abs(presum));
            rst = max(rst, m - avg);
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

