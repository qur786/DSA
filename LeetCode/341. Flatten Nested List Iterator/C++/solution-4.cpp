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
        list;

public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        list.emplace(nestedList.begin(), nestedList.end());
    }

    int next() {
        auto it = list.top().first;
        list.top().first++;
        return it->getInteger();
    }

    bool hasNext() {
        while (!list.empty()) {
            if (list.top().first == list.top().second) {
                list.pop();
                continue;
            }

            if (list.top().first->isInteger())
                return true;

            auto& li = list.top().first->getList();
            list.top().first++;
            if (!li.empty())
                list.emplace(li.begin(), li.end());
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */