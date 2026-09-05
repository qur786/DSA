class LFUCache {
private:
    int minCount = 0;
    int capacity;
    class Node {
    public:
        Node(int key, int value, int count)
            : key(key), value(value), count(count) {}
        int key, value, count;
    };
    unordered_map<int, list<Node>> countMap;
    unordered_map<int, list<Node>::iterator> keyMap;
    void insert(int key, int value) {
        if (capacity == 0)
            return;
        if (keyMap.size() == capacity) {
            auto node = countMap[minCount].begin();
            int keyToBeDeleted = node->key;
            countMap[minCount].pop_front();
            keyMap.erase(keyToBeDeleted);
        }
        minCount = 1;
        countMap[1].emplace_back(key, value, 1);
        keyMap[key] = prev(countMap[1].end());
    }
    void updateCounter(int key) {
        if (!keyMap.count(key))
            return;
        auto node = keyMap[key];
        int count = node->count;
        int value = node->value;
        countMap[node->count].erase(node);
        if (count == minCount && countMap[count].empty())
            minCount += 1;
        countMap[count + 1].emplace_back(key, value, count + 1);
        keyMap[key] = prev(countMap[count + 1].end());
    }

public:
    LFUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (!keyMap.count(key))
            return -1;
        updateCounter(key);
        return keyMap[key]->value;
    }

    void put(int key, int value) {
        if (!keyMap.count(key)) {
            insert(key, value);
        } else {
            keyMap[key]->value = value;
            updateCounter(key);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */