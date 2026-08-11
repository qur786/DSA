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
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left)
            return right;
        if (!right)
            return left;

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
        else if (right)
            curr->next = right;

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0)
            return nullptr;
        if (size == 1)
            return lists[0];

        vector<ListNode*> answers;
        answers.reserve(size / 2 + 1);
        for (int i = 0; i < size; i += 2) {
            ListNode* result = nullptr;
            if (i == size - 1)
                result = merge(lists[i], nullptr);
            else
                result = merge(lists[i], lists[i + 1]);
            answers.push_back(result);
        }
        return mergeKLists(answers);
    }
};