// Problem: Balanced Binary Tree
// Link: https://leetcode.com/problems/balanced-binary-tree
// Approach: Recursive, O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedSubtree(root).first;
    }
private:
    pair<bool, int> isBalancedSubtree(TreeNode* root) {
        if(!root) {
            return {true, 0};
        }

        auto leftResult = isBalancedSubtree(root->left);
        auto rightResult = isBalancedSubtree(root->right);

        bool balanced = leftResult.first && rightResult.first
            && (abs(leftResult.second - rightResult.second) <= 1);

        int height = 1 + max(leftResult.second, rightResult.second);
        return {balanced, height};
    }
};
