// Problem: Move Zeroes
// Link: https://leetcode.com/problems/move-zeroes
// Approach: O(n)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0;

        for (int num : nums) {
            if (num != 0) {
                nums[insertPos++] = num;
            }
        }

        while (insertPos < nums.size()) {
            nums[insertPos++] = 0;
        }
    }
};
