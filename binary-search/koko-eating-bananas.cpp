// Problem: Koko Eating Bananas
// Link: https://leetcode.com/problems/koko-eating-bananas
// Approach: Binary Search, O(logn)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *max_element(piles.begin(), piles.end());
        return answerSearch(piles, h, 1, max);
    }

    int answerSearch(vector<int>& piles, int h, int l, int r) {
        if (l == r) {
            return r;
        }

        int mid = l + (r - l) / 2;

        int hoursSpent = 0;
        for (int i = 0; i < piles.size(); i++) {
            hoursSpent += (piles[i] + mid - 1) / mid;
            if (hoursSpent > h) {
                break;
            }
        }

        if (hoursSpent > h) {
            return answerSearch(piles, h, mid + 1, r);
        } else {
            return answerSearch(piles, h, l, mid);
        }
    }
};
