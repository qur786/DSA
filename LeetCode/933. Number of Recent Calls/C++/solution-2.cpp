class RecentCounter {
private:
    deque<int> calls;

public:
    RecentCounter() {}

    int ping(int t) {
        while (!calls.empty() && (t - calls.front()) > 3000)
            calls.pop_front();
        calls.push_back(t);

        return calls.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */