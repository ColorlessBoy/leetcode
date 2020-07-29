/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0, n = data.size();
        while(i < n) {
            int num = validUtf8(data, i);
            if(num == -1) return false;
            i += num;
        }
        return true;
    }
private:
    int validUtf8(vector<int>& data, int i) {
        if(i >= data.size()) {
            return -1;
        }
        int n = data.size(), m = data[i];
        if((m & 0x80) == 0) {
            return true;
        }
        else if((m & 0xe0) == 0xc0 && n >= 2) {
            n = 2;
        }
        else if((m & 0xf0) == 0xe0 && n >= 3) {
            n = 3;
        }
        else if((m & 0xf8) == 0xf0 && n >= 4) {
            n = 4;
        }
        else {
            return -1;
        }

        for(int j = 1; j < n; ++j) {
            if((data[j + i] & 0xc0) != 0x80) {
                return -1;
            }
        }
        return n;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> data = {197, 130, 1};
    bool rst = s.validUtf8(data);
    return 0;
}

