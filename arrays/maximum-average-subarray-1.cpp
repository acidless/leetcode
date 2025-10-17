// Problem: Maximum Average Subarray I
// Link: https://leetcode.com/problems/maximum-average-subarray-i
// Approach: O(n)


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int prevValue = nums[0];
        int currentSum = accumulate(nums.begin(), nums.begin() + k, 0);
        int maxSum = currentSum;

        for(int i = k; i < nums.size(); i++) {
            currentSum = currentSum - prevValue + nums[i];
            maxSum = max(maxSum, currentSum);
            prevValue = nums[i - k + 1];
        }

        return 1.0 * maxSum / min(static_cast<int>(nums.size()), k);
    }
};
