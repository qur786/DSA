class Solution {
private:
    int deletePerson(vector<int>& candidates, int startIndex, int k) {
        if (candidates.size() == 1)
            return candidates[0];

        int deleteIndex = (startIndex + k - 1) % candidates.size();
        candidates.erase(candidates.begin() + deleteIndex);

        return deletePerson(candidates, deleteIndex, k);
    }

public:
    int findTheWinner(int n, int k) {
        vector<int> candidates(n);
        iota(candidates.begin(), candidates.end(), 1);
        return deletePerson(candidates, 0, k);
    }
};