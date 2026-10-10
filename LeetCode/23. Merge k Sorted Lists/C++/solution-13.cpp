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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        }

        l2->next = merge(l1, l2->next);
        return l2;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        if (lists.size() == 1)
            return lists[0];

        vector<ListNode*> result;
        int size = lists.size();

        for (int i = 0; i < size - 1; i += 2) {
            result.push_back(merge(lists[i], lists[i + 1]));
        }

        if (size % 2 != 0)
            result.push_back(lists[lists.size() - 1]);

        return mergeKLists(result);
    }
};