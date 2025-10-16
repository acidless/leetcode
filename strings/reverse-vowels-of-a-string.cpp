// Problem: Reverse Vowels of a String
// Link: https://leetcode.com/problems/reverse-vowels-of-a-string
// Approach: O(n)


class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels{};
        for(char c : s) {
            if(isVowel(c)) {
                vowels.push_back(c);
            }
        } 

        int idx = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i])) {
                s[i] = vowels[vowels.size() - idx - 1];
                idx++;
            }
        }

        return s;
    }
private:
    bool isVowel(char c) {
        char low = tolower(c);
        return low == 'a' || low == 'e' || low == 'i' || low == 'o' || low == 'u';
    }
};
