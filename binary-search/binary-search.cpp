// Problem: Binary Search
// Link: https://leetcode.com/problems/binary-search
// Approach: O(log(n))

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size(), target);
    }

    int binarySearch(vector<int>& nums, int l, int r, int target) {
        if(l >= r) {
            return -1;
        }

        int mid = (r + l) / 2;
        if(target == nums[mid]) {
            return mid;
        }

        if(target > nums[mid]) {
            return binarySearch(nums, mid + 1, r, target);
        } else {
            return binarySearch(nums, l, mid, target);
        }
    }
};
