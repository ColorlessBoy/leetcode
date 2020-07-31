/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N+1);
        vector<int> color(N+1, 0); // 使用 +1/-1表示两类
        for(auto edge: dislikes) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for(int i = 1; i <= N; ++i) {
            if(color[i] != 0) continue;
            stack<int> s; //使用栈来模拟dfs
            s.push(i);
            color[i] = 1; // 默认类型为1
            while(!s.empty()) {
                int node = s.top(); s.pop();
                int c = color[node];
                for(auto next: graph[node]) {
                    if(color[next] * c > 0) {
                        return false;
                    }
                    else if(color[next] == 0) {
                        s.push(next);
                        color[next] = -c;
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
    vector<vector<int>> dislikes ={{1, 2}, {1, 3}, {2, 4}};
    auto rst = s.possibleBipartition(4, dislikes);
    return 0;
}

