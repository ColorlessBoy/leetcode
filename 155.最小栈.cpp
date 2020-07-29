/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MinStack {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    stack<int> s;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        s.push(x);
        if(pq.empty() || pq.top() >= x) {
            pq.push(x);
        }
    }
    
    void pop() {
        if(pq.top() == s.top()) {
            pq.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return pq.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

