class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        array<int, 10> digitCount{};
        int answer = 0;
        int evenDigit = 0;
        for (int d : digits) {
            if (d % 2 == 0)
                evenDigit++;
            digitCount[d]++;
        }

        if (evenDigit == 0)
            return 0;

        for (int i = 100; i <= 998; i += 2) {
            string numStr = to_string(i);
            array<int, 10> dCount{};

            for (int j = 0; j < 3; j++)
                dCount[numStr[j] - '0']++;

            int p = 0;

            for (; p < 3; p++)
                if (dCount[numStr[p] - '0'] > digitCount[numStr[p] - '0'])
                    break;
            if (p > 2)
                answer++;
        }

        return answer;
    }
};