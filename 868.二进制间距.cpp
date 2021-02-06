/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
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
    int binaryGap(int N) {
        int rst = 0, cnt = 0;
        bool start_cnt = false;
        while(N) {
            cnt++;
            if(N & 1) {
                if(start_cnt) {
                    rst = max(rst, cnt);
                }
                else {
                    start_cnt = true;
                }
                cnt = 0;
            }
            N >>= 1;
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    int num = 22;
    auto rst = s.binaryGap(num);
    return 0;
}

