/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
 */

/*
 * 非常有用的随机函数
 * 蓄水池抽样
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* node = head;
        int rst = 0, cnt = 0;
        while(node) {
            cnt++;
            if(rand() % cnt == 0) {
                rst = node->val;
            }
            node = node->next;
        }
        return rst;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

int main(int argc, char **argv) {
    Solution s();

    return 0;
}

