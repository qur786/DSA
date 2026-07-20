class StockSpanner {
public:
    stack<int> st;
    vector<int> prices;
    StockSpanner() {}

    int next(int price) {
        int priceIndex = prices.size();
        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }
        int answer = st.empty() ? priceIndex + 1 : (priceIndex - st.top());
        st.push(priceIndex);
        prices.push_back(price);

        return answer;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */