// Problem: Invert Binary Tree
// Link: https://leetcode.com/problems/invert-binary-tree
// Approach: O(n)


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
    TreeNode* invertTree(TreeNode* root) {
        invertRecursive(root);
        return root;
    }
private:
    void invertRecursive(TreeNode* root) {
        if(!root) return;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertRecursive(root->left);
        invertRecursive(root->right);
    }
};
