class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int size = deck.size();
        queue<int> q;
        vector<int> answer(size);

        for (int i = 0; i < size; i++) {
            q.push(i);
        }
        int curr = 0;
        while (!q.empty()) {
            answer[q.front()] = deck[curr++];
            q.pop();
            q.push(q.front());
            q.pop();
        }

        return answer;
    }
};