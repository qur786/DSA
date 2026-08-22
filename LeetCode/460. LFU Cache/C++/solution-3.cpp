class LFUCache {
private:
    class Node {
    public:
        int key, value, count;
        Node(int key, int value, int count) {
            this->key = key;
            this->value = value;
            this->count = count;
        }
    };
    unordered_map<int, list<Node>::iterator> cache;
    unordered_map<int, list<Node>> countMap;
    int minCount;
    int capacity;
    void incrementCount(int key) {
        auto node = cache[key];
        int count = node->count;
        int value = node->value;
        countMap[count].erase(cache[key]);
        countMap[count + 1].emplace_back(key, value, count + 1);
        cache[key] = prev(countMap[count + 1].end());

        if (this->minCount == count && countMap[this->minCount].empty())
            this->minCount++;
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minCount = 0;
    }

    int get(int key) {
        if (this->capacity == 0 || !this->cache.count(key))
            return -1;
        this->incrementCount(key);
        return cache[key]->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            if (cache.size() == capacity) {
                int prevKey = countMap[this->minCount].front().key;
                cache.erase(prevKey);
                countMap[this->minCount].pop_front();
            }

            countMap[1].emplace_back(key, value, 1);
            cache[key] = prev(countMap[1].end());
            this->minCount = 1;
        } else {
            this->incrementCount(key);
            cache[key]->value = value;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */