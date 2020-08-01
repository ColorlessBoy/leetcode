/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        rcl(root, sum);
        return root;
    }
private:
    void rcl(TreeNode* node, int &sum) {
        if(!node) return;
        rcl(node->right, sum);
        node->val += sum;
        sum = node->val;
        rcl(node->left, sum);
    }

};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

