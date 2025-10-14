// Problem: Diameter of Binary Tree
// Link: https://leetcode.com/problems/diameter-of-binary-tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        int depth = 0;
        diameterRecursive(root, depth);
        return depth;
    }
private:
    int diameterRecursive(TreeNode* root, int& depth) {
        if(!root) return 0;

        int depthLeft = diameterRecursive(root->left, depth);
        int depthRight = diameterRecursive(root->right, depth);

        depth = max(depth, depthLeft + depthRight);
        return 1 + max(depthLeft, depthRight);
    }
};
