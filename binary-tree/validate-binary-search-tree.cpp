// Problem: Validate Binary Search Tree
// Link: https://leetcode.com/problems/validate-binary-search-tree
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
    bool isValidBST(TreeNode* root) {
        auto min = numeric_limits<long long>::min();
        auto max = numeric_limits<long long>::max();

        return validateBST(root, {min, max});
    }
private:
    bool validateBST(TreeNode* root, pair<long long, long long> bounds) {
        if(!root) {
            return true;
        }

        if(root->val <= bounds.first || root->val >= bounds.second) {
            return false;
        }

        return validateBST(root->left, {bounds.first, root->val})
            && validateBST(root->right, {root->val, bounds.second});
    }
};
