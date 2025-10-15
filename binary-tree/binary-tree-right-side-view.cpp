// Problem: Binary Tree Right Side View
// Link: https://leetcode.com/problems/binary-tree-right-side-view
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> result{};
        queue<TreeNode*> next{};
        next.push(root);

        while(!next.empty()) {
            int levelSize = next.size();

            TreeNode* last = nullptr;
            for(int i = 0; i < levelSize; i++) {
                TreeNode* current = next.front();
                next.pop();

                if(current) {
                    last = current;
                    next.push(current->left);
                    next.push(current->right);
                }
            }

            if(last) {
                result.push_back(last->val);
            }
        }

        return result;
    }
};
