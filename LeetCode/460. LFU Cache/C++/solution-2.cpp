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
        Node(int key, int value, int count)
            : key(key), value(value), count(count) {}
    };
    int size, minValue;
    unordered_map<int, list<Node>::iterator> keyMap;
    unordered_map<int, list<Node>*> countMap;
    LFUCache(int capacity) { size = capacity; }

    void incrementCount(int key) {
        auto node = keyMap[key];
        int count = node->count;
        int value = node->value;
        int newCount = count + 1;
        Node newNode = Node(key, value, newCount);
        countMap[count]->erase(node);
        if (!countMap.count(newCount))
            countMap[newCount] = new list<Node>();
        countMap[newCount]->push_back(newNode);
        keyMap[key] = prev(countMap[newCount]->end());

        if (minValue == count && countMap[minValue]->size() == 0)
            minValue++;
    }

    int get(int key) {
        if (!keyMap.count(key))
            return -1;
        incrementCount(key);
        return keyMap[key]->value;
    }

    void put(int key, int value) {
        if (keyMap.count(key)) {
            keyMap[key]->value = value;
            incrementCount(key);
        } else {
            if (size == keyMap.size()) {
                keyMap.erase(countMap[minValue]->front().key);
                countMap[minValue]->pop_front();
            }
            Node node = Node(key, value, 1);
            if (!countMap.count(1))
                countMap[1] = new list<Node>();
            countMap[1]->push_back(node);
            keyMap[key] = prev(countMap[1]->end());
            minValue = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */