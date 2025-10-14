// Problem: Maximum Depth of Binary Tree
// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree
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
    int maxDepth(TreeNode* root) {
        return maxDepthRecursive(root, 0);
    }
private:
    int maxDepthRecursive(TreeNode* root, int depth) {
        if(!root) return depth;

        int depthLeft = maxDepthRecursive(root->left, depth + 1);
        int depthRight = maxDepthRecursive(root->right, depth + 1);

        return max(depthLeft, depthRight);
    }
};
