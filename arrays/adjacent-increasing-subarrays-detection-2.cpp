// Problem: Adjacent Increasing Subarrays Detection II
// Link: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii
// Approach: O(n)

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int currentSize = 0;
        int prevSize = 0;
        int maxSize = 0;

        for(int i = 0; i < nums.size(); i++) {
            currentSize++;

            if(i == nums.size() - 1 || nums[i] >= nums[i + 1]) {
                maxSize = max({maxSize, currentSize / 2, min(prevSize, currentSize)});

                prevSize = currentSize;
                currentSize = 0;
            }
        }

        return maxSize;
    }
};
