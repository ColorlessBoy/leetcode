/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int rst = 0;
        if (root->left && 
            root->left->left  == nullptr &&
            root->left->right == nullptr) {
            rst += root->left->val;
        }
        rst += sumOfLeftLeaves(root->left);
        rst += sumOfLeftLeaves(root->right);
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    return 0;
}

