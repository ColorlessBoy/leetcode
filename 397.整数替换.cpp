/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int integerReplacement(int n) {
        if(n <= 1) 
            return 0;
        else if(n % 2 == 0) 
            return 1 + integerReplacement(n / 2);
        return 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    int rst = s.integerReplacement(2147483647);
    return 0;
}

