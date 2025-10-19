// Problem: Number of Recent Calls
// Link: https://leetcode.com/problems/number-of-recent-calls
// Approach: O(n)


class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int min = t - 3000;

        int start = 0;
        times.push_back(t);

        for(int i = 0; i < times.size(); i++) {
            if(times[i] >= min) {
                start = i;
                break;
            }
        }

        return times.size() - start;
    }
private:
    vector<int> times{};
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
