// Problem: Longest Subarray of 1's After Deleting One Element
// Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element
// Approach: O(n)


/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function(nums) {
    let numZeros = 1;
    let l = 0, r = 0;

    for(; r < nums.length; r++){
        numZeros -= nums[r] === 0;

        if(numZeros < 0){
            numZeros += nums[l] == 0;
            l += 1;
        }
    }

    return r - l - 1;
};
