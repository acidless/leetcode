// Problem: Decode String
// Link: https://leetcode.com/problems/decode-string
// Approach: Stack, O(n)


class Solution {
public:
    string decodeString(string s) {
        string result = "";
        stack<pair<string, int>> repeats{};
    
        int repeatCount = 0;
        for (char c : s) {
            if (isdigit(c)) {
                repeatCount = repeatCount * 10 + (c - '0');
            } else if (isalpha(c)) {
                result += c;
            } else if (c == '[') {
                repeats.push({result, repeatCount});
                result = "";
                repeatCount = 0;
            } else if (c == ']') {
                auto [previousString, previousRepeatCount] = repeats.top();
                repeats.pop();
                string repeatedString = "";
                for (int i = 0; i < previousRepeatCount; i++) {
                    repeatedString += result;
                }

                result = previousString + repeatedString;
            }
        }
    
        return result;
    }
};
