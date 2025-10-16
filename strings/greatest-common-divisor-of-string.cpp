// Problem: Greatest Common Divisor of Strings
// Link: https://leetcode.com/problems/greatest-common-divisor-of-strings
// Approach: Finding gcd of strings sizes, O(n + m)

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) {
            return "";
        }

        int gcdSize = gcd(str1.size(), str2.size());
        return str2.substr(0, gcdSize);
    }
};
