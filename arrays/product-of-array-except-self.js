// Problem: Product of Array Except Self
// Link: https://leetcode.com/problems/product-of-array-except-self
// Approach: O(n)

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    const res = Array(nums.length).fill(1);
    let prefix = 1, postfix = 1;

    let j = nums.length - 1;
    for(let i = 0;i<nums.length;i++){
        res[i] *= prefix;
        res[j] *= postfix;
        prefix *= nums[i];
        postfix *= nums[j];

        j--;
    }

    return res;
};
