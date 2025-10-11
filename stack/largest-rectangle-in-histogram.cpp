// Problem: Largest Rectangle in Histogram
// Link: https://leetcode.com/problems/largest-rectangle-in-histogram
// Approach: Stack, O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> stack;

        for (int i = 0; i <= n; i++) {
            while (!stack.empty() &&
                 (i == n || heights[stack.top()] >= heights[i])) {
                int height = heights[stack.top()];
                stack.pop();
              
                int width = stack.empty() ? i : i - stack.top() - 1;
                maxArea = max(maxArea, height * width);
            }
          
            stack.push(i);
        }
        return maxArea;
    }
};
