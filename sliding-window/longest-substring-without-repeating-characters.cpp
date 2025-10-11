// Problem: Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters
// Approach: Sliding window, O(n)


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> substr{};
        int l = 0, r = 0;
        int maxLength = 0;

        while(r < s.size()) {
            char ch = s[r];
            if(substr.find(ch) != substr.end()) {
                l = std::max(substr[ch] + 1, l);
            }

            substr[ch] = r;
            maxLength = max(r - l + 1, maxLength);
            r++;
        }

        return maxLength;
    }
};
