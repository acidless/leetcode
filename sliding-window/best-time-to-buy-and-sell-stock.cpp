// Problem: Best Time to Buy and Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
// Approach: Sliding window, O(n)


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxProfit = 0;

        while(r < prices.size()) {
            int profit = prices[r] - prices[l];
            if(profit > 0) {
                maxProfit = max(maxProfit, profit);
            } else {
                l = r;
            }

            r++;
        }

        return maxProfit;
    }
};
