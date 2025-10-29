// Problem: Path Sum II
// Link: https://leetcode.com/problems/path-sum-ii
// Approach: DFS, O(n)


/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} targetSum
 * @return {number[][]}
 */
var pathSum = function(root, targetSum) {
    const result = [];
    const currentPath = [];

    function dfs(root, remaining) {
        if(!root) {
            return;
        }

        remaining -= root.val;

        currentPath.push(root.val);

        if(!root.left && !root.right && remaining === 0) {
            result.push([...currentPath]);
        }

        dfs(root.left, remaining);
        dfs(root.right, remaining);

        currentPath.pop();
    }

    dfs(root, targetSum);
    

    return result;
};
