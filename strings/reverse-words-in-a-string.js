// Problem: Reverse Words in a String
// Link: https://leetcode.com/problems/reverse-words-in-a-string

/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.split(" ").filter(s => s.trim()).reverse().join(" ");
};
