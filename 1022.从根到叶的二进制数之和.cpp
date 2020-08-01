/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
private:
    int base = pow(10, 9) + 7;
    void dfs(TreeNode* node, int num, int& sum) {
        if(!node) return;
        num = (num << 1) | (node->val);
        if(!node->left && !node->right) {
            //叶子节点
            sum = (sum + num % base) % base;
            return;
        }
        dfs(node->left, num, sum);
        dfs(node->right,num, sum);
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

