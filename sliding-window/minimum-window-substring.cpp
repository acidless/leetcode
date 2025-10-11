// Problem: Minimum Window Substring
// Link: https://leetcode.com/problems/minimum-window-substring
// Approach: Sliding window, O(n+m)


class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }

        unordered_map<char, int> freqT;
        for (char c : t) {
            freqT[c]++;
        }

        int required = freqT.size();
        int formed = 0;
        unordered_map<char, int> windowCount;

        int l = 0, r = 0;
        int bestLen = numeric_limits<int>::max();
        int bestL = 0;

        while (r < s.size()) {
            char c = s[r];
            windowCount[c]++;

            if (freqT.count(c) && windowCount[c] == freqT[c]) {
                formed++;
            }
                
            while (l <= r && formed == required) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestL = l;
                }

                char leftChar = s[l];
                windowCount[leftChar]--;
                if (freqT.count(leftChar) && windowCount[leftChar] < freqT[leftChar]) {
                    formed--;
                }

                l++;
            }

            r++;
        }

        return bestLen == numeric_limits<int>::max() ? "" : s.substr(bestL, bestLen);
    }
};
