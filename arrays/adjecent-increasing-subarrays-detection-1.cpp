// Problem: Adjacent Increasing Subarrays Detection I
// Link: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i
// Approach: O(n)


class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int currentLength = 0;
        int prevLength = 0;
        int maxLength = 0;

        for(int i = 0; i < nums.size(); i++) {
            currentLength++;

            if(i == nums.size() - 1 || nums[i] >= nums[i + 1]) {
                maxLength = max({maxLength, currentLength / 2, min(prevLength, currentLength)});

                prevLength = currentLength;
                currentLength = 0;
            }
        }

        return maxLength >= k;
    }
};
