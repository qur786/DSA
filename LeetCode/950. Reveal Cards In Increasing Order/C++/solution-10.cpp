class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), greater<int>());
        int size = deck.size();
        deque<int> dq;
        dq.push_back(deck[0]);

        for (int i = 1; i < size; i++) {
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(deck[i]);
        }

        vector<int> result;
        result.reserve(size);

        while (!dq.empty()) {
            result.push_back(dq.front());
            dq.pop_front();
        }

        return result;
    }
};