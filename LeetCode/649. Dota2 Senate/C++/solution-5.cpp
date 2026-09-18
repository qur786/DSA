class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dq, rq;
        int size = senate.size();

        for (int i = 0; i < size; i++) {
            if (senate[i] == 'R')
                rq.push(i);
            else
                dq.push(i);
        }

        while (!dq.empty() && !rq.empty()) {
            int dindex = dq.front();
            dq.pop();
            int rindex = rq.front();
            rq.pop();

            if (rindex < dindex) {
                rq.push(rindex + size);
            } else {
                dq.push(dindex + size);
            }
        }

        return dq.empty() ? "Radiant" : "Dire";
    }
};