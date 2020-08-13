/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

/*
 * 1. 方法一：自顶向下
 * 排序: h从低到高， k从高到低；
 * [[4, 4], [5, 2], [5, 0], [6, 1], [7. 1], [7, 0]]
 * 首先 [4, 4] 所在的下标一定是4；
 * 递归求解: [[5, 2], [5, 0], [6, 1], [7, 1], [7, 0]]
 * 2. 方法二：自底向上
 * 排序：h从高到低，k从低到高；
 * [[7, 0], [7. 1], [6, 1], [5, 0], [5, 2], [4, 4]]
 * 不断插入：
 * 例如: 
 * 将 [6, 1] 插入到数组 [[7, 0], [7, 1]] 的 1 号位；
 * 将 [5, 0] 插入到数组 [[7, 0], [6, 1], [7, 1]] 的 0 号位。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(),
        [&](vector<int> &a, vector<int> &b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });

        vector<vector<int>> rst(n, vector<int>(2, 0));
        for(int idx = 0; idx < n; ++idx) {
            int start = people[idx][1];
            for(int j = idx; j > start; --j) {
                rst[j] = rst[j-1];
            }
            rst[start] = people[idx];
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    auto rst = s.reconstructQueue(people);
    return 0;
}

