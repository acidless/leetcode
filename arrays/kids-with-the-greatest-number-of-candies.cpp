// Problem: Kids With the Greatest Number of Candies
// Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies
// Approach: O(n)


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size(), false);

        int maxCandies = *max_element(candies.begin(), candies.end());

        for(int i = 0; i < candies.size(); i++) {
            if(candies[i] + extraCandies >= maxCandies) {
                result[i] = true;
            }
        }

        return result;
    }
};
