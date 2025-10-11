# Problem: Two Sum II - Input Array Is Sorted
# Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
# Approach: Two pointers, O(n)


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers) - 1

        while l < r:
            if target - numbers[r] < numbers[l]:
                r -= 1
            elif target - numbers[r] - numbers[l] == 0:
                return [l + 1, r + 1]
            else:
                l += 1
