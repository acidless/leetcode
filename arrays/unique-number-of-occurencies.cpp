// Problem: Unique Number of Occurrences
// Link: https://leetcode.com/problems/unique-number-of-occurrences
// Approach: O(n)


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count{};

        for(auto elem : arr) {
            if(count.find(elem) == count.end()) {
                count[elem] = 1;
            } else {
                count[elem]++;
            }
        }

        unordered_set<int> uniqueCount{};
        for(auto& pair : count) {
            if(uniqueCount.count(pair.second)) {
                return false;
            }

            uniqueCount.insert(pair.second);
        }

        return true;
    }
};
