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
    void reverse(ListNode* head) {
        if (!head || !head->next)
            return;

        reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)
            return head;

        int count = 1;
        ListNode* curr = head;

        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        if (!curr)
            return head;
        ListNode* result = reverseKGroup(curr->next, k);
        curr->next = nullptr;
        reverse(head);
        head->next = result;

        return curr;
    }
};