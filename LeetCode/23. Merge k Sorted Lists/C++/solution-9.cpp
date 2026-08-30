/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* merge(ListNode* first, ListNode* second) {
        if (!first)
            return second;
        if (!second)
            return first;

        ListNode* result = nullptr;

        if (first->val <= second->val) {
            result = first;
            first->next = merge(first->next, second);
        } else {
            result = second;
            second->next = merge(first, second->next);
        }

        return result;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        if (lists.size() == 1)
            return lists[0];

        ListNode* second = lists.back();
        lists.pop_back();
        ListNode* first = lists.back();
        lists.pop_back();

        lists.push_back(merge(first, second));

        return mergeKLists(lists);
    }
};