// Problem: Find the Difference of Two Arrays
// Link: https://leetcode.com/problems/find-the-difference-of-two-arrays
// Approach: O(n)


class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
      
        vector<vector<int>> result(2);
      
        for (int value : set1) {
            if (!set2.count(value)) {
                result[0].push_back(value);
            }
        }
      
        for (int value : set2) {
            if (!set1.count(value)) {
                result[1].push_back(value);
            }
        }
      
        return result;
    }
};
