class LRUCache {
   public:
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(const int key) {
        for (int i = 0; i < (int)cache.size(); ++i) {
            if (cache[i].first == key) {
                const pair<int, int> temp = cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(temp);
                return temp.second;
            }
        }
        return -1;
    }

    void put(const int key, const int value) {
        for (int i = 0; i < (int)cache.size(); ++i) {
            if (cache[i].first == key) {
                cache[i] = pair(key, value);
                const pair<int, int> temp = cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(temp);
                return;
            }
        }

        if (cache.size() == capacity) {
            cache.erase(cache.begin());
        }

        cache.emplace_back(key, value);
    }

    vector<pair<int, int>> cache;
    int capacity;
};
