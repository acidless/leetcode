# Problem: Container With Most Water
# Link: https://leetcode.com/problems/container-with-most-water
# Approach: O(n)

class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r = 0, len(heights) - 1
        max_val = 0

        while l < r:
            max_val = max(min(heights[l], heights[r]) * (r - l), max_val)

            if heights[l] < heights[r]:
                l += 1
            else:
                r -= 1
                
        return max_val
