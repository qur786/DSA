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
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left)
            return right;
        if (!right)
            return left;

        if (left->val <= right->val) {
            left->next = merge(left->next, right);
            return left;
        }
        right->next = merge(left, right->next);
        return right;
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

        lists.push_back(merge(left, right));

        return mergeKLists(lists);
    }
};