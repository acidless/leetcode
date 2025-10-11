// Problem: Trapping Rain Water
// Link: https://leetcode.com/problems/trapping-rain-water
// Approach: Prefix and suffix arrays, O(n)

class Solution {
public:
    int trap(vector<int>& height) {
        std::vector<int> prefix(height.size());
        std::vector<int> suffix(height.size());

        int currentMax = height[0];
        for(int i = 0; i < height.size(); i++) {
            prefix[i] = currentMax;
            currentMax = std::max(currentMax, height[i]);
        }

        currentMax = height[height.size() - 1];
        for(int i = height.size() - 1; i >= 0; i--) {
            suffix[i] = currentMax;
            currentMax = std::max(currentMax, height[i]);
        }

        int result = 0;
        for(int i = 0; i < height.size(); i++) {
            result += std::max(std::min(prefix[i], suffix[i]) - height[i], 0);
        }

        return result;
    }
};
