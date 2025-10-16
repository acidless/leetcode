// Problem: Can Place Flowers
// Link: https://leetcode.com/problems/can-place-flowers
// Approach: O(n)

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size(); i++) {
            if(!n) {
                return true;
            }

            auto leftEmpty = (!i || !flowerbed[i - 1]);
            auto rightEmpty = (i >= flowerbed.size() - 1 || !flowerbed[i + 1]);
            auto currentEmpty = !flowerbed[i];

            if(leftEmpty && rightEmpty && currentEmpty) {
                n--;
                flowerbed[i] = 1;
            }

        }

        return !n;
    }
};
