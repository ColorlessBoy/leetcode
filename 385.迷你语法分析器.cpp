/*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] 迷你语法分析器
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        int i = 0;
        return deserialize(s, i);
    }
private:
    NestedInteger deserialize(string &s, int &i) {
        NestedInteger rst;
        int isNum = false, isSequence = false;

        //查找当前节点的类型。
        while(i < s.size() && !isNum && !isSequence) {
            char ch = s[i];
            //没有判定节点类型时，先找能判断类型的字符
            if(ch == '-' || ch >= '0' && ch <= '9') {
                isNum = true;
                break;
            }
            else if(ch == '[') {
                isSequence = true;
                break;
            }
            ++i;
        }

        if(isNum) {
            int val = 0, sign = 1;
            while(i < s.size()) {
                char ch = s[i];
                if(ch == '-') {
                    sign = -1;
                }
                else if(ch >= '0' && ch <= '9') {
                    val = val * 10 + ch - '0';
                }
                else {
                    break;
                }
                ++i;
            }
            rst.setInteger(val * sign);
        }
        else {
            ++i;
            while(s[i] != ']') {
                rst.add(deserialize(s, i));
            }
            ++i;
        }

        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s();
    return 0;
}

