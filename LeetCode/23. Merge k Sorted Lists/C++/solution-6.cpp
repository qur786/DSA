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

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        int size = lists.size();
        vector<ListNode*> sortedLists;

        for (int i = 0; i < size; i += 2) {
            if (i + 1 == size)
                sortedLists.push_back(lists[i]);
            else
                sortedLists.push_back(merge(lists[i], lists[i + 1]));
        }

        return mergeKLists(sortedLists);
    }
};