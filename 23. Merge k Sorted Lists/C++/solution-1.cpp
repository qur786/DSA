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
public:
    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if (list1)
            curr->next = list1;
        if (list2)
            curr->next = list2;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        int size = lists.size();
        vector<ListNode*> result;
        for (int i = 0; i < size; i += 2) {
            ListNode *list1 = lists[i], *list2 = nullptr;
            if (i == (size - 1))
                list2 = nullptr;
            else
                list2 = lists[i + 1];
            ListNode* res = mergeLists(list1, list2);
            result.push_back(res);
        }
        return mergeKLists(result);
    }
};