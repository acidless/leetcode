// Problem: Construct Binary Tree from Preorder and Inorder Traversal
// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, numeric_limits<int>::max());
    }
private:
    int preIdx = 0;
    int inIdx = 0;

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int limit) {
        if(preIdx >= preorder.size()) {
            return nullptr;
        }

        if(inorder[inIdx] == limit) {
            inIdx++;
            return nullptr;
        }

        auto node = new TreeNode(preorder[preIdx++]);
        node->left = dfs(preorder, inorder, node->val);
        node->right = dfs(preorder, inorder, limit);
        return node;
    }
};
