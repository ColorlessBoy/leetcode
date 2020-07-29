/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第K小的元素
 */

/*
 * 非常特别的二分法 + 有序矩阵的统计方式。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty())
            return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        if(cols == 0) return 0;
        int l = matrix[0][0], r = matrix[rows-1][cols-1];
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(countSmaller(matrix, mid) < k) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return l;
    }
private:
    int countSmaller(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int r = rows - 1, c = 0;
        int ans = 0;
        while(r >= 0) {
            while(c < cols && matrix[r][c] <= target) {
                c++;
            }
            ans += c;
            r--;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> matrix = {};
    int rst = s.kthSmallest(matrix, 0);
    return 0;
}

