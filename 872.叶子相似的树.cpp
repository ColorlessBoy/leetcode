/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        dfs(root1, leaves1);
        dfs(root2, leaves2);

        return leaves1 == leaves2;
    }

    void dfs(TreeNode* node, vector<int>& leaves) {
        if (node == NULL) return;
        if (node->left == NULL && node->right == NULL)
            leaves.push_back(node->val);
        dfs(node->left, leaves);
        dfs(node->right, leaves);
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

