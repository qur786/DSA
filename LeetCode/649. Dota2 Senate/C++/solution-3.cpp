class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rIndices, dIndices;
        int size = senate.size();

        for (int i = 0; i < size; i++)
            if (senate[i] == 'D')
                dIndices.push(i);
            else
                rIndices.push(i);

        while (!rIndices.empty() && !dIndices.empty()) {
            int rindex = rIndices.front();
            rIndices.pop();
            int dindex = dIndices.front();
            dIndices.pop();

            if (rindex < dindex) {
                rIndices.push(rindex + size);
            } else {
                dIndices.push(dindex + size);
            }
        }

        return rIndices.empty() ? "Dire" : "Radiant";
    }
};