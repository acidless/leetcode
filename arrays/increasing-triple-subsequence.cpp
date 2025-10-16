// Problem: Increasing Triplet Subsequence
// Link: https://leetcode.com/problems/increasing-triplet-subsequence
// Approach: O(n)


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int smallest = numeric_limits<int>::max();
        int middle = numeric_limits<int>::max();
      
        for (int current : nums) {
            if (current > middle) {
                return true;
            }
          
            if (current <= smallest) {
                smallest = current;
            }
            else {
                middle = current;
            }
        }
      
        return false;
    }
};
