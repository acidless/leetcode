// Problem: Max Consecutive Ones III
// Link: https://leetcode.com/problems/max-consecutive-ones-iii
// Approach: O(n)


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int maxOnes = 0;
        int currentK = k;

        while (r < nums.size()) {
            if (nums[r] == 0) {
                currentK--;
            }

            while (currentK < 0) {
                if (nums[l] == 0) {
                    currentK++;
                }
                
                l++;
            }

            maxOnes = max(maxOnes, r - l + 1);
            r++;
        }

        return maxOnes;
    }
};
