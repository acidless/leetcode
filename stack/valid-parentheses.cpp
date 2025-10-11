// Problem: Valid Parentheses
// Link: https://leetcode.com/problems/valid-parentheses
// Approach: Stack, O(n)

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> brackets{};

        for(const auto& c : s) {
            if(c == '(' || c == '{' || c == '[') {
                brackets.push(c);
            } else {
                if(!brackets.size()) {
                    return false;
                }

                auto opening =  brackets.top();
                brackets.pop();
                if(c == ')' && opening != '(' || 
                   c == '}' && opening != '{' ||
                   c == ']' && opening != '['
                ) {
                    return false;
                }
            }
        }

        return brackets.size() == 0;
    }
};
