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
        if (!head || !head->next)
            return head;

        ListNode* curr = head;
        for (int count = 1; count < k; count++) {
            curr = curr->next;
            if (!curr)
                return head;
        }

        ListNode* nextList = curr->next;
        curr->next = nullptr;
        ListNode* reverseHead = reverse(head);
        head->next = reverseKGroup(nextList, k);

        return reverseHead;
    }
};