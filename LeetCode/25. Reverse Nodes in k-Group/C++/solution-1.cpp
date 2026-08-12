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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next)
            return head;

        int count = 1;
        ListNode* curr = head;
        while (count < k && curr) {
            curr = curr->next;
            if (curr)
                count++;
        }

        if (count == k) {
            ListNode* temp = curr->next;
            curr->next = nullptr;
            ListNode* reverseHead = reverse(head);
            head->next = reverseKGroup(temp, k);
            return reverseHead;
        }

        return head;
    }
};