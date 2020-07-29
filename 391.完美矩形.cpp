/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 */

/*
 * 1. 肯定要排序。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        // 获得最大矩形, 顺带统计一下小矩阵的面积和。
        long long sum = 0;
        vector<int> largeRec = {INT_MAX, INT_MAX, 0, 0};
        for(auto &rec: rectangles) {
            largeRec[0] = min(largeRec[0], rec[0]);
            largeRec[1] = min(largeRec[1], rec[1]);
            largeRec[2] = max(largeRec[2], rec[2]);
            largeRec[3] = max(largeRec[3], rec[3]);
            sum += area(rec);
        }
        if(sum != area(largeRec)) {
            return false;
        }
        // 判断是否矩形有重叠。
        set<pair<int, int>> s;
        rectangles.push_back(largeRec);
        for(auto &rec: rectangles) {
            for(int i = 0; i <= 2; i += 2) {
                for(int j = 1; j <= 3; j += 2) {
                    auto a = make_pair(rec[i], rec[j]);
                    if(s.find(a) != s.end()) {
                        s.erase(s.find(a));
                    }
                    else {
                        s.insert(a);
                    }
                }
            }
        }
        return s.empty();
    }
private:
    inline long long area(vector<int> &rec) {
        return (rec[2] - rec[0]) * (rec[3] - rec[1]);
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    // vector<vector<int>> rectangles = {{1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};
    vector<vector<int>> rectangles = {{0, 0, 1, 1}, {0, 0, 2, 1}, {1, 0, 2, 1}, {0, 2, 2, 3}};
    s.isRectangleCover(rectangles);
    return 0;
}

