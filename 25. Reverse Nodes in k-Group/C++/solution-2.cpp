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
    ListNode* reverse(ListNode* head) {
        ListNode *curr = head, *prev = nullptr, *next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode *curr = head, *next = nullptr;

        while (curr) {
            count++;
            if (count == k) {
                next = curr->next;
                curr->next = nullptr;
                break;
            }
            curr = curr->next;
        }

        if (count < k)
            return head;

        ListNode* rhead = reverse(head);
        head->next = reverseKGroup(next, k);

        return rhead;
    }
};