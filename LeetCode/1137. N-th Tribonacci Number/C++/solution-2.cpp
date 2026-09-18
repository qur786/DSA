class Solution {
private:
    vector<int> tri = vector<int>(38, -1);
    int getTri(int n) {
        if (tri[n] != -1)
            return tri[n];

        tri[n] = getTri(n - 1) + getTri(n - 2) + getTri(n - 3);

        return tri[n];
    }

public:
    int tribonacci(int n) {
        tri[0] = 0;
        tri[1] = 1;
        tri[2] = 1;

        return getTri(n);
    }
};