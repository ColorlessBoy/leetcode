/*
 * @lc app=leetcode.cn id=826 lang=cpp
 *
 * [826] 安排工作以达到最大收益
 */

/*
 * Notes:
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& workers) {
        if(difficulty.empty()) return 0;
        int n = difficulty.size();
        vector<pair<int, int>> jobs;
        for(int i = 0 ; i < n ; ++i) {
            jobs.push_back(make_pair(difficulty[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end(), 
            [](pair<int, int>&a, pair<int,int>&b) {
                if(a.first == b.first)
                    return a.second < b.second;
                return a.first < b.first;
            });
        vector<pair<int, int>> jobs2;
        for(auto & job: jobs) {
            if(jobs2.empty() || jobs2.back().second < job.second) {
                   jobs2.push_back(job);
               }
        }

        int max_profit = 0;
        reverse(jobs2.begin(), jobs2.end()); // 为了求首个不大于
        for(auto &worker : workers) {
            auto iter = lower_bound(jobs2.begin(), jobs2.end(), worker,
                    [](pair<int, int> &element, const int &value) {
                        return element.first > value;
                    });
            // 首个不大于
            if(iter != jobs2.end())
                max_profit += iter->second;
        }
        return max_profit;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<int> difficulty = {2, 4, 6, 8, 10};
    vector<int> profit = {10, 20, 30, 40, 50};
    vector<int> worker = {4, 5, 6, 7};
    auto rst = s.maxProfitAssignment(difficulty, profit, worker);
       
    return 0;
}

