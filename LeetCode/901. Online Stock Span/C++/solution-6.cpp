class StockSpanner {
private:
    stack<int> st;
    vector<int> prices;

public:
    StockSpanner() {}

    int next(int price) {
        int currentIndex = prices.size();
        while (!st.empty() && (price >= prices[st.top()])) {
            st.pop();
        }
        int span = st.empty() ? (currentIndex + 1) : (currentIndex - st.top());
        st.push(currentIndex);
        prices.push_back(price);

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */