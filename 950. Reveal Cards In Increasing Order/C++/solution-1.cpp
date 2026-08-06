class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> dq;
        sort(deck.begin(), deck.end(), greater<int>());
        int size = deck.size();
        vector<int> result;
        result.reserve(size);

        for (int i = 0; i < size; i++) {
            if (!dq.empty()) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.push_front(deck[i]);
        }

        while (!dq.empty()) {
            result.push_back(dq.front());
            dq.pop_front();
        }

        return result;
    }
};