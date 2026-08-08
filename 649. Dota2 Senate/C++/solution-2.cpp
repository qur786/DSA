class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        int size = senate.size();

        for (int i = 0; i < size; i++) {
            if (senate[i] == 'R')
                r.push(i);
            else
                d.push(i);
        }

        while (!r.empty() && !d.empty()) {
            int rindex = r.front();
            r.pop();
            int dindex = d.front();
            d.pop();

            if (rindex < dindex) {
                r.push(rindex + size);
            } else {
                d.push(dindex + size);
            }
        }

        return r.empty() ? "Dire" : "Radiant";
    }
};