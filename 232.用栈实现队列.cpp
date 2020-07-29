/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MyQueue {
private:
    stack<int> in;
    stack<int> out;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
  
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int rst = out.top();
        out.pop();
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return rst;
    }
    
    /** Get the front element. */
    int peek() {
        return out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

