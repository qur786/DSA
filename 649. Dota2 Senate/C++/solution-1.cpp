class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> d, r;
        int size = senate.size();

        for (int i = 0; i < size; i++)
            if (senate[i] == 'D')
                d.push(i);
            else
                r.push(i);

        while (!d.empty() && !r.empty()) {
            int rIndex = r.front();
            r.pop();
            int dIndex = d.front();
            d.pop();

            if (rIndex < dIndex) {
                r.push(rIndex + size);
            } else {
                d.push(dIndex + size);
            }
        }

        return d.empty() ? "Radiant" : "Dire";
    }
};