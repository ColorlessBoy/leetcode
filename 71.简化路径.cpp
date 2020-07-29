/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> dq;
        string file;
        path.push_back('/');
        for(auto &ch : path) {
            if(ch == '/') {
                if(file == "..") {
                    if(!dq.empty()) 
                        dq.pop_back();
                }
                else if(!file.empty() && file != ".") {
                    dq.push_back(file);
                }
                file.clear();
            }
            else {
                file.push_back(ch);
            }
        }
        string rst;
        while(!dq.empty()) {
            rst.push_back('/');
            rst += dq.front();
            dq.pop_front();
        }
        return rst.empty()? "/" : rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string str = "/../";
    str = s.simplifyPath(str);
    return 0;
}

