class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), greater<int>());
        int size = deck.size();
        deque<int> dq;
        vector<int> answer;
        answer.reserve(size);

        dq.push_front(deck[0]);
        for (int i = 1; i < size; i++) {
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(deck[i]);
        }

        while (!dq.empty()) {
            answer.push_back(dq.front());
            dq.pop_front();
        }

        return answer;
    }
};