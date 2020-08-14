/*
 * @lc app=leetcode.cn id=546 lang=cpp
 *
 * [546] 移除盒子
 */

/*
 * 我们要求最大积分和，是一个求最值问题，非常符合动态规划的问题类型。
 * 那么现在状态如何表示呢？
 * dp[i][j]: 
 *   - boxes[i] 和 boxes[j] 不一起划的时候，dp[i][k]+dp[k+1][j]的最大值。
 *   - a = boxes[i] == boxes[j], 可以计算一下这两个一起划的结果, 这个很难算；
 *     如果boxes[i+1 .. j-1] 之间还有 t 个 a，这 t 个 a 哪些可以和 boxes[i]、boxes[j] 一起被划掉呢？
 *     那就有 2^t 种可能。
 *     这是一个动态规划的子问题，我们可以再增加一个维度的动态规划。
 * dp[i][j][k]: 表示 boxes[i .. j] 之间和 j 一起被划掉的数字的个数为 k 时，能得到的最大分数。
 * 因为 boxes[j] 是数组的最右边，所以和它一起被划掉的数一定可以最后被划掉。
 * 那么，动态转移方程是什么呢？
 * dp[i][j][0]
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        if(n <= 1) return n;
        int dp[100][100][100] = {};
        return dfs(boxes, dp, 0, n - 1, 0);
    }
private:
    int dfs(vector<int>& boxes, int dp[100][100][100], int i, int j, int k) {
        if(j < i) return 0;
        if(dp[i][j][k] > 0) return dp[i][j][k];
        while(j > i && boxes[j-1] == boxes[j]) {
            j--;
            k++;
        }
        dp[i][j][k] = max(dp[i][j][k], dfs(boxes, dp, i, j - 1, 0) + (k + 1) * (k + 1));
        for(int mid = i; mid < j; ++mid) {
            if(boxes[mid] == boxes[j]) {
                dp[i][j][k] = max(dp[i][j][k], dfs(boxes, dp, i, mid, k+1)+dfs(boxes, dp, mid+1, j-1, 0));
            }
        }
        return dp[i][j][k];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> boxes = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    auto rst = s.removeBoxes(boxes);
    return 0;
}

