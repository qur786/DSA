class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int size = deck.size();
        vector<int> result(size);
        queue<int> q;

        for (int i = 0; i < size; i++)
            q.push(i);

        int curr = 0;

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            result[front] = deck[curr++];

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return result;
    }
};