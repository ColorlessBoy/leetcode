/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> length = {-1};//第一层
        bool isFile = false;
        int str_length = 0, deepth = 1, rst = 0;
        for(auto &ch: input) {
            if(ch == '\n') {
                if(isFile) {
                    rst = max(rst, length[deepth-1] + 1 + str_length);
                } 
                else {
                    int tmp = length[deepth-1] + 1 + str_length;
                    if(length.size() == deepth) {
                        length.push_back(tmp);
                    }
                    else {
                        length[deepth] = tmp;
                    }
                }
                str_length = 0;
                deepth = 1;
                isFile = false;
            }
            else if(ch == '\t') {
                deepth++;
            }
            else if(ch == '.') {
                str_length++;
                isFile = true;
            }
            else {
                str_length++;
            }
        }
        if(isFile) {
            rst = max(rst, length[deepth-1] + 1 + str_length);
        } 
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    // string str = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    string str = "dir\n\t        file.txt\n\tfile2.txt";
    int rst = s.lengthLongestPath(str);
    return 0;
}

