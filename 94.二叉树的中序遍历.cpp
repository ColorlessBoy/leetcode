/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rst;
        stack<TreeNode*> s;
        while(root) {
            s.push(root);
            root = root->left;
        }
        while(!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            rst.push_back(node->val);
            node = node->right;
            while(node) {
                s.push(node);
                node = node->left;
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

