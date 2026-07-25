class LFUCache {
public:
    class Node {
    public:
        int key, value, count;
        Node() {
            key = 0;
            value = 0;
            count = 0;
        }
        Node(int key, int value, int count) {
            this->key = key;
            this->value = value;
            this->count = count;
        }
    };
    unordered_map<int, list<Node>::iterator> keyNodeMap;
    unordered_map<int, list<Node>*> freqNodeMap;
    int capacity, minFrequency;

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFrequency = 0;
    }

    void incrementCounter(int key) {
        if (!keyNodeMap.count(key))
            return;
        auto node = keyNodeMap[key];
        int prevCount = node->count;
        node->count++;
        if (!freqNodeMap.count(node->count))
            freqNodeMap[node->count] = new list<Node>();
        freqNodeMap[node->count]->push_back(
            Node(node->key, node->value, node->count));
        keyNodeMap[key] = prev(freqNodeMap[node->count]->end());
        freqNodeMap[prevCount]->erase(node);
        if (freqNodeMap[prevCount]->empty() && prevCount == minFrequency)
            minFrequency++;
    }

    int get(int key) {
        if (!keyNodeMap.count(key))
            return -1;
        incrementCounter(key);
        auto node = keyNodeMap[key];
        return node->value;
    }

    void put(int key, int value) {
        if (keyNodeMap.count(key)) {
            incrementCounter(key);
            keyNodeMap[key]->value = value;
        } else {
            if (keyNodeMap.size() == capacity) {
                int key = freqNodeMap[minFrequency]->front().key;
                keyNodeMap.erase(key);
                freqNodeMap[minFrequency]->pop_front();
            }
            minFrequency = 1;
            if (!freqNodeMap.count(minFrequency))
                freqNodeMap[minFrequency] = new list<Node>();
            freqNodeMap[minFrequency]->push_back(Node(key, value, 1));
            keyNodeMap[key] = prev(freqNodeMap[minFrequency]->end());
        }
    }

    ~LFUCache() {
        for (auto [count, it] : freqNodeMap)
            delete it;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */