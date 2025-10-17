// Problem: Determine if Two Strings Are Close
// Link: https://leetcode.com/problems/determine-if-two-strings-are-close
// Approach: O(nlogn)

class Solution {
public:
    inline auto analyzeString(string& word){
        unordered_set<char> set{};
        array<char, 26> arr{};

        for(char ch : word){
            arr[ch - 'a']++;
            set.insert(ch);
        }

        sort(arr.begin(), arr.end());

        return pair<unordered_set<char>, array<char, 26>>(set, arr);
    }

    bool closeStrings(string word1, string word2) {
        auto pair1 = analyzeString(word1);
        auto pair2 = analyzeString(word2);

        return pair1.first == pair2.first && pair1.second == pair2.second;
    }
};
