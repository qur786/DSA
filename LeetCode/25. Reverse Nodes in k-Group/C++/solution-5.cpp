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
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* reverseHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return reverseHead;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)
            return head;

        int count = 1;
        ListNode* curr = head;
        while (count < k && curr->next) {
            curr = curr->next;
            count++;
        }

        if (count < k)
            return head;

        ListNode* reversed = reverseKGroup(curr->next, k);
        curr->next = nullptr;
        ListNode* reverseHead = reverse(head);
        head->next = reversed;

        return curr;
    }
};