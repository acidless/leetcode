# Problem: Valid Palindrome
# Link: https://leetcode.com/problems/valid-palindrome
# Approach: Two pointers, O(n)

class Solution:
    def isPalindrome(self, s: str) -> bool:
        j, i = len(s) - 1, 0

        while i < j:
            while i < j and not s[i].lower().isalnum():
                i += 1
            while j > i and not s[j].lower().isalnum():
                j -= 1

            if s[i].lower() != s[j].lower():
                return False
            i += 1
            j -= 1
        return True
