// Problem: Partition Labels
// Link: https://leetcode.com/problems/partition-labels
// Approach: Two pointers, O(n)

/**
 * @param {string} s
 * @return {number[]}
 */
var partitionLabels = function(s) {
    const lastIndex = new Array(26);

    function getIndex(ch) {
        return ch.charCodeAt(0) - "a".charCodeAt(0);
    }

    for(let i = 0; i < s.length; i++) {
        lastIndex[getIndex(s[i])] = i;
    }

    const results = [];

    let start = 0;
    let end = 0;
    for(let i = 0; i < s.length; i++) {
        end = Math.max(end, lastIndex[getIndex(s[i])]);

        if(end === i) {
            results.push(i - start + 1);
            start = i + 1;
        }
    }

    return results;
};
