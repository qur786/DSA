/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer
 * to it. void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
    int curr = 0;
    void setInteger(NestedInteger& ni, string& num) {
        if (!num.empty()) {
            ni.add(NestedInteger(stoi(num)));
            num = "";
        }
    }

public:
    NestedInteger deserialize(string s) {
        NestedInteger ni;
        string num;

        if (s[0] != '[') {
            ni.setInteger(stoi(s));
            return ni;
        }

        while (curr < s.size()) {
            if (s[curr] == '[') {
                if (curr > 0) {
                    setInteger(ni, num);
                    curr++;
                    ni.add(deserialize(s));
                }
            } else if (s[curr] == ']') {
                setInteger(ni, num);
                return ni;
            } else if (s[curr] == ',') {
                setInteger(ni, num);
            } else {
                num.push_back(s[curr]);
            }
            curr++;
        }

        return ni;
    }
};