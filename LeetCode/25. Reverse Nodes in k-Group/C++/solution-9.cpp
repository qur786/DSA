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
        if (!head || !head -> next)
            return head;

        ListNode* reverseHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;

        return reverseHead;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode *curr = head, *prev = nullptr;
        while (curr && count < k) {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if (count < k)
            return head;
        prev->next = nullptr;
        reverse(head);
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};