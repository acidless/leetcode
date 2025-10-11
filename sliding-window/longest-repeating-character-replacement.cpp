// Problem: Longest Repeating Character Replacement
// Link: https://leetcode.com/problems/longest-repeating-character-replacement
// Approach: Sliding window, O(n)


class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxCount = 0;
        int maxLength = 0;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            maxCount = max(maxCount, count[s[r] - 'A']);

            while ((r - l + 1) - maxCount > k) {
                count[s[l] - 'A']--;
                l++;
            }

            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};
