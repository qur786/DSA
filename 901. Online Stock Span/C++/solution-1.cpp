class StockSpanner {
public:
    vector<int> prices;
    stack<int> st;
    StockSpanner() {}

    int next(int price) {
        int index = prices.size();
        prices.push_back(price);
        while (!st.empty() && price >= prices[st.top()]) {
            st.pop();
        }
        int ans = 1;
        if (!st.empty())
            ans = index - st.top();
        else
            ans = index + 1;
        st.push(index);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */