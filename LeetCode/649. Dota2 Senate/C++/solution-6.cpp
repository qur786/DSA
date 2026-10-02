class Solution {
public:
    string predictPartyVictory(string senate) {
        int size = senate.size();
        queue<int> dq, rq;

        for (int i = 0; i < size; i++)
            if (senate[i] == 'R')
                rq.push(i);
            else
                dq.push(i);

        while (!rq.empty() && !dq.empty()) {
            int rindex = rq.front();
            rq.pop();
            int dindex = dq.front();
            dq.pop();

            if (rindex < dindex)
                rq.push(rindex + size);
            else
                dq.push(dindex + size);
        }

        return dq.empty() ? "Radiant" : "Dire";
    }
};