/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        if(n <= 2) return false;
        for(int i = 1; i <= n / 2; ++i) {
            for(int j = i + 1; j < n; ++j) {
                string a = num.substr(0, i);
                string b = num.substr(i, j - i);
                if(a.size() > 1 && a[0] == '0'
                    || b.size() > 1 && b[0] == '0')
                    continue;
                int idx = j;
                while(idx < n) {
                    string tmp = add(a, b);
                    if(num.find(tmp, idx) != idx) {
                        break;
                    }
                    idx += tmp.size();
                    swap(a, b);
                    swap(b, tmp);
                }
                if(idx == n) return true;
            }
        }
        return false;
    }
private:
    string add(string a, string b) {
        int m = a.size(), n = b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string c;
        int flag = 0;
        for(int i = 0, j = 0; i < m || j < n; ++i, ++j) {
            int x = (i >= m)? 0 : a[i] - '0';
            int y = (j >= n)? 0 : b[j] - '0';
            flag += x + y;
            c.push_back(flag % 10 + '0');
            flag /= 10;
        }
        if(flag) c.push_back(flag + '0');
        return string(c.rbegin(), c.rend());
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string str = "123";
    auto rst = s.isAdditiveNumber(str);
    return 0;
}

