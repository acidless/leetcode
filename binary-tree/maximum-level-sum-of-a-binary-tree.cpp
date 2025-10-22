// Problem: Maximum Level Sum of a Binary Tree
// Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree
// Approach: BFS, O(n)

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q{};
        q.push(root);

        int maxLevelSum = numeric_limits<int>::min();
        int maxLevel = 1;
        int currentLevel = 1;

        while(!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;

            for(int i = 0; i < levelSize; i++) {
                auto node = q.front();
                q.pop();

                if(node) {
                    levelSum += node->val;

                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }

            if(levelSum > maxLevelSum) {
                maxLevelSum = levelSum;
                maxLevel = currentLevel;
            }

            currentLevel++;
        }

        return maxLevel;
    }
};
