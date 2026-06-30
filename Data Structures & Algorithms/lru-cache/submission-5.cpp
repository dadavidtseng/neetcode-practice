class LRUCache {
   public:
    explicit LRUCache(const int capacity) { this->capacity = capacity; }

    int get(const int key) {
        if (!cache.contains(key)) {
            return -1;
        }

        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second = --order.end();
        return cache[key].first;
    }

    void put(const int key, const int value) {
        if (cache.contains(key)) {
            order.erase(cache[key].second);
        } else if (static_cast<int>(cache.size()) == capacity) {
            const int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }
        order.push_back(key);
        cache[key] = {value, --order.end()};
    }

    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
    int capacity;
};
