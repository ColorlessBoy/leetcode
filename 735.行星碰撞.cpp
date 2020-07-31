/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(auto &a: asteroids) {
            while(!s.empty() && a < 0 && s.top() > 0) {
                int &b = s.top();
                if(b > -a) {
                    a = 0;
                }
                else if(b == -a) {
                    a = 0;
                    s.pop();
                }
                else {
                    s.pop();
                }
            }
            if(a) s.push(a);
        }
        vector<int> rst;
        while(!s.empty()) {
            rst.push_back(s.top());
            s.pop();
        }
        return vector<int>(rst.rbegin(), rst.rend());
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

