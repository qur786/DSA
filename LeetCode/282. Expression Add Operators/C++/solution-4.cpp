class Solution {
private:
    vector<string> answer;
    void addOps(string& nums, const string& comb, int target, int size,
                long long valueSoFar, long long prevNum, int index) {
        if (index == size) {
            if (valueSoFar == target)
                answer.push_back(comb);
            return;
        }

        string numStr;
        long long num = 0;
        for (int i = index; i < size; i++) {
            if (i > index && nums[index] == '0')
                return;
            numStr.push_back(nums[i]);
            num = num * 10 + nums[i] - '0';
            if (index == 0)
                addOps(nums, comb + numStr, target, size, num, num, i + 1);
            else {
                addOps(nums, comb + "+" + numStr, target, size,
                       valueSoFar + num, num, i + 1);
                addOps(nums, comb + "-" + numStr, target, size,
                       valueSoFar - num, -num, i + 1);
                addOps(nums, comb + "*" + numStr, target, size,
                       valueSoFar - prevNum + prevNum * num, prevNum * num,
                       i + 1);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        addOps(num, "", target, num.size(), 0, 0, 0);

        return answer;
    }
};