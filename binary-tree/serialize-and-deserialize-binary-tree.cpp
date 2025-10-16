// Problem: Serialize and Deserialize Binary Tree
// Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree
// Approach: Recursive, O(n)


/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
const serialize = function(root) {
    const result = [];
    serializeDFS(root, result);
    return result.join(",");
};

const serializeDFS = function (root, result) {
    if(root == null) {
        result.push("N");
        return;
    }

    result.push(root.val.toString());
    serializeDFS(root.left, result);
    serializeDFS(root.right, result);
}

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
const deserialize = function(data) {
    const values = data.split(",");
    const curr = {idx: 0};
    return deserializeDFS(values, curr);
};

const deserializeDFS = function(values, curr) {
    if(values[curr.idx] === "N") {
        curr.idx++;
        return null;
    }

    const node = new TreeNode(parseInt(values[curr.idx++]));
    node.left = deserializeDFS(values, curr);
    node.right = deserializeDFS(values, curr);
    return node;
}


/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */
