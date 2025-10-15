// Problem: Kth Smallest Element in a BST
// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst
// Approach: Stack, O(n)


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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> nodes;
        TreeNode* curr = root;

        while (!nodes.empty() || curr != nullptr) {
            while (curr != nullptr) {
                nodes.push(curr);
                curr = curr->left;
            }

            curr = nodes.top();
            nodes.pop();
            
            k--;
            if (k == 0) {
                return curr->val;
            }

            curr = curr->right;
        }

        return -1;
    }
};
