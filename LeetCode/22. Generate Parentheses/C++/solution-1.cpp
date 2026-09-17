class Solution {
private:
    void genParen(vector<string>& answer, vector<char>& availableComb,
                  string& comb, vector<bool>& visited, int size, int leftCount,
                  int rightCount) {
        if (comb.size() == size) {
            answer.push_back(comb);
            return;
        }

        for (int i = 0; i < size; i++) {
            if (leftCount > rightCount)
                continue;
            if (visited[i])
                continue;
            if (i > 0 && availableComb[i] == availableComb[i - 1] &&
                !visited[i - 1])
                continue;
            if (availableComb[i] == '(')
                leftCount--;
            else
                rightCount--;
            comb.push_back(availableComb[i]);
            visited[i] = true;
            genParen(answer, availableComb, comb, visited, size, leftCount,
                     rightCount);
            if (availableComb[i] == '(')
                leftCount++;
            else
                rightCount++;
            visited[i] = false;
            comb.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string comb;
        int size = n * 2;
        vector<bool> visited(size, false);
        vector<char> availableComb;
        availableComb.reserve(size);

        for (int i = 0; i < n; i++)
            availableComb.push_back('(');
        for (int i = 0; i < n; i++)
            availableComb.push_back(')');
        genParen(answer, availableComb, comb, visited, size, n, n);

        return answer;
    }
};