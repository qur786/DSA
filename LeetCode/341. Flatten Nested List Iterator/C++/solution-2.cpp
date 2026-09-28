/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<pair<vector<NestedInteger>::const_iterator,
               vector<NestedInteger>::const_iterator>>
        st;

public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        if (!nestedList.empty()) {
            st.push({nestedList.begin(), nestedList.end()});
        }
    }

    int next() {
        auto it = st.top().first;
        st.top().first++;
        return it->getInteger();
    }

    bool hasNext() {
        while (!st.empty()) {
            auto& [curr, end] = st.top();

            if (curr == end) {
                st.pop();
                continue;
            }

            if (curr->isInteger()) {
                return true;
            }

            const auto& subList = curr->getList();
            curr++;

            if (!subList.empty()) {
                st.push({subList.begin(), subList.end()});
            }
        }

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */