class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), greater<int>());
        deque<int> dq;
        int size = deck.size();

        for (int i = 0; i < size; i++) {
            if (!dq.empty()) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.push_front(deck[i]);
        }

        vector<int> result;

        while (!dq.empty()) {
            result.push_back(dq.front());
            dq.pop_front();
        }
        return result;
    }
};