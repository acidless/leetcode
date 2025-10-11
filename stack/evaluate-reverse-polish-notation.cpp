// Problem: Evaluate Reverse Polish Notation
// Link: https://leetcode.com/problems/evaluate-reverse-polish-notation
// Approach: Stack, O(n)


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<string> operands{};

        for(const auto& token : tokens) {
            if(token != "+" && token != "-" && token != "*" && token != "/") {
                operands.push(token);
                continue;
            }

            auto first = stoi(operands.top());
            operands.pop();
            auto second = stoi(operands.top());
            operands.pop();

            switch(token[0]) {
                case '+': 
                    operands.push(std::to_string(second + first));
                    break;
                case '-': 
                    operands.push(std::to_string(second - first));
                    break;
                case '*': 
                    operands.push(std::to_string(second * first));
                    break;
                case '/': 
                    operands.push(std::to_string(second / first));
                    break;
            }
        }

        return stoi(operands.top());
    }
};
