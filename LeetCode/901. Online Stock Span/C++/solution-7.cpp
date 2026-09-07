class StockSpanner {
private:
    vector<int> prices;
    stack<int> st;

public:
    StockSpanner() {}

    int next(int price) {
        int index = prices.size();
        prices.push_back(price);
        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }
        int result = index - (st.empty() ? -1 : st.top());
        st.push(index);

        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */