// Problem: Asteroid Collision
// Link: https://leetcode.com/problems/asteroid-collision
// Approach: Stack, O(n)


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack{};
      
        for (int a : asteroids) {
            if (a > 0) {
                stack.push_back(a);
            } 
            else {
                while (!stack.empty() && stack.back() > 0 && stack.back() < -a) {
                    stack.pop_back();
                }
              
                if (!stack.empty() && stack.back() == -a) {
                    stack.pop_back();
                } 
                else if (stack.empty() || stack.back() < 0) {
                    stack.push_back(a);
                }
            }
        }
      
        return stack;
    }
};
