/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * {785} 判断二分图
 */

// 这道题和栈有什么关系呢？
// 用栈实现dfs。

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        set<int> A, B;
        stack<int> s;
        for(int i = 0; i < graph.size(); ++i) {
            if(A.find(i) == A.end() && B.find(i) == B.end()) {
                s.push(i);
                A.insert(i);
            }
            while(!s.empty()) {
                int node = s.top(); s.pop();
                if(B.find(node) != B.end()) {
                    swap(A, B);
                }
                for(auto next: graph[node]) {
                    if(A.find(next) != A.end()) {
                        return false;
                    }
                    else if(B.find(next) == B.end()) {
                        B.insert(next);
                        s.push(next);
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    // vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    vector<vector<int>> graph = {{},{2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}};
    auto rst = s.isBipartite(graph);
    return 0;
}

