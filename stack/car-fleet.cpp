// Problem: Car Fleet
// Link: https://leetcode.com/problems/car-fleet/
// Approach: Sort, Stack, O(nlogn)


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        std::sort(pair.rbegin(), pair.rend());

        std::stack<double> stack;
        for (auto& p : pair) {
            auto val = static_cast<double>(target - p.first) / p.second;
            if (stack.size() == 0 || val > stack.top())
            {
                stack.push(val);
            }
        }
        return stack.size();
    }
};
