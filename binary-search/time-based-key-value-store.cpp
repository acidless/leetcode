// Problem: Time Based Key-Value Store
// Link: https://leetcode.com/problems/time-based-key-value-store
// Approach: set: O(1), get: O(logn)

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> keyStore;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto& values = keyStore[key];
        int l = 0;
        int r = values.size() - 1;
        string result = "";

        while (l <= r) {
            int mid = (l + r) / 2;

            if (values[mid].first <= timestamp) {
                result = values[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;
    }
};
