/*
 * @lc app=leetcode.cn id=636 lang=cpp
 *
 * [636] 函数的独占时间
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> table(n, 0);
        stack<pair<int, int>> sp;
        for(auto &s: logs) {
            vector<int> vi = parser(s);
            if(vi[1] == 1) {
                sp.push({vi[0], vi[2]});
            }
            else {
                auto p = sp.top(); sp.pop();
                table[p.first] += vi[2] - p.second + 1;
                if(!sp.empty()) {
                    table[sp.top().first] -= vi[2] - p.second + 1;
                }
            }
        }
        return table;
    }
private:
    vector<int> parser(string &s) {
        string cur;
        int n1 = s.find(':');
        int n2 = s.find(':', n1 + 1);
        int a = stoi(s.substr(0, n1));
        int b = stoi(s.substr(n2+1));
        string c = s.substr(n1+1, n2-n1-1);
        if(c == "start") {
            return {a, 1, b};
        }
        return {a, -1, b};
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<string> log = {"0:start:0",
                        "1:start:2",
                        "1:end:5",
                        "0:end:6"};
    auto rst = s.exclusiveTime(2, log);
    return 0;
}

