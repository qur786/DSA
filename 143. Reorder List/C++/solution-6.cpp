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
    ListNode* getMiddleNode(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode *slow = head, *fast = head->next->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middleNode = slow->next;
        slow->next = nullptr;
        return middleNode;
    }
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *curr = head, *prev = nullptr, *next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    void merge(ListNode* left, ListNode* right) {
        if (!left || !right)
            return;

        while (right) {
            ListNode* temp = left->next;
            left->next = right;
            left = left->next;
            right = temp;
        }
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        ListNode* middleNode = getMiddleNode(head);
        ListNode* reverseSecondHalfHead = reverse(middleNode);
        merge(head, reverseSecondHalfHead);
    }
};