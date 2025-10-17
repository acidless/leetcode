// Problem: Is Subsequence
// Link: https://leetcode.com/problems/is-subsequence
// Approach: O(n)

/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    let j = 0;

    for(let i = 0; i < t.length; i++){
        if(s[j] === t[i]) {
            j++;
        }
    }

    return j === s.length;
};
