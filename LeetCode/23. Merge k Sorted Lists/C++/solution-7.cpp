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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode* result = nullptr;
        if (list1->val <= list2->val) {
            list1->next = merge(list1->next, list2);
            result = list1;
        } else {
            list2->next = merge(list1, list2->next);
            result = list2;
        }

        return result;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        if (lists.size() == 1)
            return lists[0];

        int size = lists.size();
        vector<ListNode*> result;
        result.reserve(size / 2 + 1);

        for (int i = 0; i < (size - 1); i += 2) {
            ListNode* res = merge(lists[i], lists[i + 1]);
            result.push_back(res);
        }

        if (size % 2 != 0)
            result.push_back(lists.back());

        return mergeKLists(result);
    }
};