// Problem: LRU Cache
// Link: https://leetcode.com/problems/lru-cache


class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {
        
    }
    
    int get(int key) {
        if(cache_.find(key) == cache_.end()) {
            return -1;
        }

        order_.erase(cache_[key].second);
        order_.push_back(key);

        cache_[key].second = --order_.end();
        return cache_[key].first;
    }
    
    void put(int key, int value) {
        if (cache_.find(key) != cache_.end()) {
            order_.erase(cache_[key].second);
        } else if (cache_.size() == capacity_) {
            int lru = order_.front();
            order_.pop_front();
            cache_.erase(lru);
        }

        order_.push_back(key);
        cache_[key] = {value, --order_.end()};
    }
private:
    unordered_map<int, pair<int, list<int>::iterator>> cache_;
    list<int> order_;
    int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
