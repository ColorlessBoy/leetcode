/*
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
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
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[0] > rec2[0])
            swap(rec1, rec2);
        if(rec1[0] <= rec2[0] && rec1[2] > rec2[0]) {
            if(rec1[1] >= rec2[3] || rec1[3] <= rec2[1])
                return false;
            return true;
        }
        return false;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    return 0;
}

