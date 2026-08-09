class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        int size = deck.size();
        vector<int> result(size);

        for (int i = 0; i < size; i++)
            q.push(i);
        int curr = 0;
        while (!q.empty()) {
            result[q.front()] = deck[curr++];
            q.pop();
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return result;
    }
};