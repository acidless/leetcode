// Problem: 3Sum
// Link: https://leetcode.com/problems/3sum/
// Approach: Like two sum, but fix one of the numbers, O(n^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result{};

        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target = -nums[i];

            int l = i + 1;
            int r = nums.size() - 1;

            while(l < r) {
                if(target - nums[r] < nums[l]) {
                    r--;
                } else if(target - nums[r] - nums[l] == 0) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                } else {
                    l++;
                }
            }
        }

        return result;
    }
};
