// Problem: Leaf-Similar Trees
// Link: https://leetcode.com/problems/leaf-similar-trees
// Approach: DFS, O(n)


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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1{};
        vector<int> leafs2{};

        collectLeafs(root1, leafs1);
        collectLeafs(root2, leafs2);

        return leafs1 == leafs2;
    }
private:
    void collectLeafs(TreeNode* root, vector<int>& leafs) {
        if(!root) {
            return;
        }

        if(!root->left && !root->right) {
            leafs.push_back(root->val);
            return;
        }

        collectLeafs(root->left, leafs);
        collectLeafs(root->right, leafs);
    }
};
