// Problem: Find Resultant Array After Removing Anagrams
// Link: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams
// Approach: O(n * m)


class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        array<int, 26> prevCount{};
        bool hasPrev = false;

        for (const string& word : words) {
            array<int, 26> count{};
            for (char c : word) {
                count[c - 'a']++;
            }

            if (!hasPrev || count != prevCount) {
                result.push_back(word);
                prevCount = count;
                hasPrev = true;
            }
        }

        return result;
    }
};
