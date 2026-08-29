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

        ListNode* second = lists.back();
        lists.pop_back();
        ListNode* first = lists.back();
        lists.pop_back();

        lists.push_back(merge(first, second));

        return mergeKLists(lists);
    }
};