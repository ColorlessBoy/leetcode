/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
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
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.empty()) return {};
        int n = A.size();
        int idx = n-1;
        for(int i = 0; i < idx; ++i) {
            while(i < idx && (A[i] & 1)) {
                swap(A[i], A[idx--]);
            }
        }
        return A;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    return 0;
}

