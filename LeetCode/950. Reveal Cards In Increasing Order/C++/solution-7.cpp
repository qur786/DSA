class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int size = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> cardIndices;
        vector<int> result(size);

        for (int i = 0; i < size; i++) {
            cardIndices.push(i);
        }

        int curr = 0;
        while (!cardIndices.empty()) {
            int front = cardIndices.front();
            cardIndices.pop();
            if (!cardIndices.empty()) {
                cardIndices.push(cardIndices.front());
                cardIndices.pop();
            }
            result[front] = deck[curr];
            curr++;
        }

        return result;
    }
};