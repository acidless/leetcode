// Problem: Removing Stars From a String
// Link: https://leetcode.com/problems/removing-stars-from-a-string
// Approach: O(n)


class Solution {
public:
    string removeStars(string s) {
        string result = "";

        for(char c : s) {
            if(c != '*') {
                result.push_back(c);
            } else {
                result.pop_back();
            }
        }

        return result;
    }
};
