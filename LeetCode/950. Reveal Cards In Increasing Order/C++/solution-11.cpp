class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int size = deck.size();
        vector<int> result(size);
        sort(deck.begin(), deck.end());
        queue<int> q;

        for (int i = 0; i < size; i++)
            q.push(i);

        int curr = 0;
        while (!q.empty()) {
            result[q.front()] = deck[curr++];
            q.pop();

            q.push(q.front());
            q.pop();
        }

        return result;
    }
};