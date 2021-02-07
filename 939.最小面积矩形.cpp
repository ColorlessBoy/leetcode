/*
 * @lc app=leetcode.cn id=939 lang=cpp
 *
 * [939] 最小面积矩形
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
    int minAreaRect(vector<vector<int>>& points) {
        if(points.size() < 4) return 0;
        int width = 40000, size = points.size(), area = INT_MAX;
        unordered_set<int> us;
        for(auto &p: points) {
            us.insert(p[0] * width + p[1]);
        }
        for(int i = 0; i < size; ++i) {
            for(int j = i + 1; j < size; ++j) {
                if(points[i][0] != points[j][0]
                && points[i][1] != points[j][1]) {
                    if(us.find(points[i][0] * width + points[j][1]) != us.end()
                    && us.find(points[j][0] * width + points[i][1]) != us.end()) {
                        int tmp = (points[i][0] - points[j][0])
                                * (points[i][1] - points[j][1]);
                        if(tmp < 0) tmp = -tmp;
                        area = min(area, tmp);
                    }
                }
            }
        }
        if(area == INT_MAX) return 0;
        return area;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    return 0;
}

