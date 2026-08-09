class StockSpanner {
public:
    stack<int> monotonicDecreasingPriceDays;
    vector<int> prices;
    StockSpanner() {}

    int next(int price) {
        int currentIndex = prices.size();
        int ans = currentIndex;
        while (!monotonicDecreasingPriceDays.empty() &&
               prices[monotonicDecreasingPriceDays.top()] <= price) {
            monotonicDecreasingPriceDays.pop();
        }
        int left = monotonicDecreasingPriceDays.empty()
                       ? -1
                       : monotonicDecreasingPriceDays.top();

        ans = currentIndex - left;

        monotonicDecreasingPriceDays.push(currentIndex);
        prices.push_back(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */