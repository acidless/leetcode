// Problem: Smallest Missing Non-negative Integer After Operations
// Link: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations
// Approach: O(n)


class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> remaindersCount(value, 0);

        for(int num : nums) {
            auto remainder = ((num % value) + value) % value;
            remaindersCount[remainder]++;
        }

        int i = 0;
        while(true) {
            auto remainder = i % value;
            if(remaindersCount[remainder] == 0) {
                return i;
            }

            remaindersCount[remainder]--;

            i++;
        }
    }
};
