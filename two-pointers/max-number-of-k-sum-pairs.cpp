// Problem: Max Number of K-Sum Pairs
// Link: https://leetcode.com/problems/max-number-of-k-sum-pairs
// Approach: Sorting, then two pointers, O(nlogn)


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.size() - 1;
        int operations = 0;
        while(l < r) {
            if(nums[r] + nums[l] > k) {
                r--;
            } else if(nums[r] + nums[l] < k) {
                l++;
            } else {
                operations++;
                r--;
                l++;
            }
        }

        return operations;
    }
};
