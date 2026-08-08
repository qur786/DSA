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
    ListNode* mergeSortedLists(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (left && right) {
            if (left->val <= right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }

        if (left)
            curr->next = left;
        if (right)
            curr->next = right;

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

        ListNode* right = lists.back();
        lists.pop_back();
        ListNode* left = lists.back();
        lists.pop_back();
        lists.push_back(this->mergeSortedLists(left, right));

        return mergeKLists(lists);
    }
};