class StockSpanner {
public:
    vector<int> prices;
    stack<int> st;
    StockSpanner() {}

    int next(int price) {
        int i = prices.size();
        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }
        int value;
        if (!st.empty())
            value = i - st.top();
        else
            value = i + 1;
        st.push(i);
        prices.push_back(price);

        return value;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */