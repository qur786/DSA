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
    ListNode* splitMiddle(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head->next->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = slow->next;
        slow->next = nullptr;

        return middle;
    }
    ListNode* mergeSort(ListNode* left, ListNode* right) {
        if (!left && !right)
            return nullptr;
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* middle = this->splitMiddle(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(middle);
        ListNode* newHead = mergeSort(left, right);

        return newHead;
    }
};