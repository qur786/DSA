class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), greater<int>());
        int size = deck.size();
        deque<int> cards;

        cards.push_back(deck[0]);
        for (int i = 1; i < size; i++) {
            cards.push_front(cards.back());
            cards.pop_back();
            cards.push_front(deck[i]);
        }

        for (int i = 0; i < size; i++) {
            deck[i] = cards.front();
            cards.pop_front();
        }

        return deck;
    }
};