/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> rst;
        vector<int> level;
        deque<TreeNode*> dq;
        bool flag = true;
        dq.push_back(root);
        TreeNode* end = root;
        while(!dq.empty()) {
            if(flag) {
                TreeNode* node = dq.front(); dq.pop_front();
                level.push_back(node->val);
                if(node->left) dq.push_back(node->left);
                if(node->right) dq.push_back(node->right);
                if(node == end) {
                    rst.push_back(level);
                    level.clear();
                    flag = !flag;
                    end = dq.front();
                }
            }
            else {
                TreeNode* node = dq.back(); dq.pop_back();
                level.push_back(node->val);
                if(node->right) dq.push_front(node->right);
                if(node->left) dq.push_front(node->left);
                if(node == end) {
                    rst.push_back(level);
                    level.clear();
                    flag = !flag;
                    end = dq.back();
                }
            }
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    return 0;
}

