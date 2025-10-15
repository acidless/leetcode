// Problem: Count Good Nodes in Binary Tree
// Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree
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
    int goodNodes(TreeNode* root) {
        return dfs(root, numeric_limits<int>::min());
    }
private:
    int dfs(TreeNode* root, int maxVal) {
        if(!root) return 0;

        int addOne = root->val >= maxVal;
        int newMax = max(maxVal, root->val);

        return dfs(root->left, newMax) + dfs(root->right, newMax) + addOne;
    }
};
