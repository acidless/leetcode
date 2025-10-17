// Problem: Maximum Number of Vowels in a Substring of Given Length
// Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length
// Approach: O(n)


class Solution {
public:
    int maxVowels(string s, int k) {
        int currentSize = 0;
        for(int i = 0; i < k; i++) {
            if(isVowel(s[i])) {
                currentSize++;
            } 
        }

        char prevChar = s[0];
        int maxSize = currentSize;
        for(int i = k; i < s.size(); i++) {
            if(isVowel(s[i])) {
                currentSize++;
            }

            if(isVowel(prevChar)) {
                currentSize--;
            }

            maxSize = max(maxSize, currentSize);
            prevChar = s[i - k + 1];
        }


        return maxSize;
    }
private:
    inline bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
