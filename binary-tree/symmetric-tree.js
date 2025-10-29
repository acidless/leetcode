// Problem: Symmetric Tree
// Link: https://leetcode.com/problems/symmetric-tree
// Approach: Recursive, O(n)

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
 * @return {boolean}
 */
var isSymmetric = function(root) {
    if(!root) {
        return true;
    }

    return symmetricCheck(root.left, root.right);
};

function symmetricCheck(left, right) {
    if(!left && !right) {
        return true;
    }

    if(!left || !right || right.val !== left.val) {
        return false;
    }

    return symmetricCheck(left.left, right.right) && symmetricCheck(left.right, right.left);
}
