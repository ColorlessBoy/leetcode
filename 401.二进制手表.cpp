/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<vector<int>> hours = {{0}, {1, 2, 4, 8}, {3, 5, 6, 9, 10},{7, 11}};
        vector<vector<int>> minites(9);
        for(int i = 0; i < 60; ++i) {
            minites[count(i)].push_back(i);
        }
        vector<string> rst;
        for(int i = 0; i < hours.size(); ++i) {
            if(num - i >= 0 && num - i < minites.size()) {
                for(auto hour: hours[i]) {
                    for(auto minite: minites[num - i]) {
                        rst.push_back(getTime(hour, minite));
                    }
                }
            }
        }
        return rst;
    }
private:
    int count(int n) {
        int cnt = 0;
        while(n > 0) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt;
    }
    string getTime(int &hour, int &minite) {
        string str = "";
        if(minite < 10)
            return to_string(hour) + ":0" + to_string(minite);
        return to_string(hour) + ":" + to_string(minite);
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    s.readBinaryWatch(1);
    return 0;
}

