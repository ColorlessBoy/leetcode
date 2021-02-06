/*
 * @lc app=leetcode.cn id=911 lang=cpp
 *
 * [911] 在线选举
 */

/*
 * Notes:
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class TopVotedCandidate {
private:
    vector<int> ps;
    vector<int> ts;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times)
        :ps(persons), ts(times) {
        unordered_map<int, int> cnt;
        int top_p = 0;
        for(int i = 0; i < ps.size(); ++i) {
            cnt[persons[i]]++;
            if(cnt[persons[i]] >= cnt[top_p]) {
                top_p = persons[i];
            }
            ps[i] = top_p;
        }
    }
    
    int q(int t) {
        // binary search
        int left = 0, right = ts.size();
        while(left < right) {
            int mid = left + (right - left)/2;
            if(ts[mid] == t) {
                return ps[mid];
            } else if(ts[mid] > t) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return ps[left-1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end

int main(int argc, char **argv) {
    vector<int> persons = {0, 1, 0, 1, 1};
    vector<int> times = {24, 29, 31, 76, 81};
    TopVotedCandidate s(persons, times);
    int rst = s.q(75);
    return 0;
}

