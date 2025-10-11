// Problem: Generate Parentheses
// Link: https://leetcode.com/problems/generate-parentheses
// Approach: Stack + Backtracking


class Solution {
public:
    void backtrack(int opened, int closed, int n, std::string& stack, std::vector<string>& result) {
        if(opened == closed && opened == n) {
            result.push_back(stack);
            return;
        }

        if(opened < n) {
            stack += "(";
            backtrack(opened + 1, closed, n, stack, result);
            stack.pop_back();
        }

        if(closed < opened) {
            stack += ")";
            backtrack(opened, closed + 1, n, stack, result);
            stack.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        std::vector<string> result{};
        std::string stack = "";
        backtrack(0, 0, n, stack, result);
        return result;
    }
};
