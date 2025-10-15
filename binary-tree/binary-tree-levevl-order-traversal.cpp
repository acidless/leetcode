// Problem: Binary Tree Level Order Traversal
// Link: https://leetcode.com/problems/binary-tree-level-order-traversal
// Approach: Queue, O(n)

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> result{};
        queue<TreeNode*> next{};
        next.push(root);
        
        while(!next.empty()) {
            vector<int> level{};
            int levelSize = next.size();

            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = next.front();
                next.pop();

                if(node) {
                    level.push_back(node->val);
                    next.push(node->left);
                    next.push(node->right);
                }
            }

            if(!level.empty()) {
                result.push_back(level);
            }
        }

        return result;
    }
};
