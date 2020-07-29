/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        if(equations.empty()) return {};
        int n = equations.size();
        graph.clear();
        for(int i = 0; i < n; ++i) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        vector<double> rst;
        for(auto &iter: queries) {
            visited.clear();
            rst.push_back(dfs(iter[0], iter[1]));
        }
        return rst;
    }
private:
    unordered_map<string, vector<pair<string, double>>> graph;
    unordered_set<string> visited;
    double dfs(string &start, string &target) {
        if(visited.find(start) != visited.end()
            || graph.find(start) == graph.end())
            return -1.0;
        else if(start == target)
            return 1.0;

        auto &root = graph[start];
        visited.insert(start);
        double rst = -1.0;
        for(auto &next: root) {
            double tmp = dfs(next.first, target);
            if(tmp > 0) return next.second * tmp;
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    auto rst = s.calcEquation(equations, values, queries);
    return 0;
}

