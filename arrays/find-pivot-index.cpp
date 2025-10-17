// Problem: Find Pivot Index
// Link: https://leetcode.com/problems/find-pivot-index
// Approach: O(n)


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size, 0);
        vector<int> postfix(size, 0);

        for(int i = 1; i < size; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
            postfix[size - i - 1] = postfix[size - i] + nums[size - i];
        }

        for(int i = 0; i < size; i++) {
            if(prefix[i] == postfix[i]) {
                return i;
            }
        }

        return -1;
    }
};
