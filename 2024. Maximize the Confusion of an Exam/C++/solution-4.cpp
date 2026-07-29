class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left = 0, maxFreq = 0, size = answerKey.size(), maxLen = 0,
            tCount = 0, fCount = 0;

        for (int right = 0; right < size; right++) {
            if (answerKey[right] == 'T')
                tCount++;
            else
                fCount++;

            maxFreq = max({maxFreq, tCount, fCount});

            if ((right - left + 1) > (maxFreq + k)) {
                if (answerKey[left] == 'T')
                    tCount--;
                else
                    fCount--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};