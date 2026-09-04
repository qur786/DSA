class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rNodes, dNodes;

        int size = senate.size();

        for (int i = 0; i < size; i++)
            if (senate[i] == 'D')
                dNodes.push(i);
            else
                rNodes.push(i);

        while (!rNodes.empty() && !dNodes.empty()) {
            int rFront = rNodes.front();
            rNodes.pop();
            int dFront = dNodes.front();
            dNodes.pop();

            if (rFront < dFront)
                rNodes.push(rFront + size);
            else
                dNodes.push(dFront + size);
        }

        return rNodes.empty() ? "Dire" : "Radiant";
    }
};