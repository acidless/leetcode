// Problem: Merge Strings Alternately
// Link: https://leetcode.com/problems/merge-strings-alternately
// Approach: O(n)

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int first = 0, second = 0;
        std::string result = "";
        while(first < word1.size() || second < word2.size()) {
            if((i & 1) == 1 && second < word2.size()) {
                result += word2[second++];
            } else if(first < word1.size()) {
                result += word1[first++];
            }

            i++;
        }

        return result;
    }
};
