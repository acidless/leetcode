// Problem: Subtree of Another Tree
// Link: https://leetcode.com/problems/subtree-of-another-tree
// Approach: Recursive, O(n*m)


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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) {
            return true;
        }
        if (!root) {
            return false;
        }

        if (isSameTrees(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
private:
    bool isSameTrees(TreeNode* p, TreeNode* q) {
        if(!p && !q) {
            return true;
        } else if(p && q && p->val == q->val) {
            return isSameTrees(p->left, q->left) && isSameTrees(p->right, q->right);
        } else {
            return false;
        }
    }
};
