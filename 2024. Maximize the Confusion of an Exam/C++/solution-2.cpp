class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int size = answerKey.size(), left = 0, maxLen = 0, tCount = 0,
            fCount = 0, maxOcc = 0;

        for (int right = 0; right < size; right++) {
            if (answerKey[right] == 'T')
                tCount++;
            else
                fCount++;

            maxOcc = max(tCount, fCount);
            if ((maxOcc + k) < (right - left + 1)) {
                if (answerKey[left] == 'T')
                    tCount--;
                else
                    fCount--;
                left += 1;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};