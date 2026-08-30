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

        ListNode* curr = head;
        int count = 1;

        while (curr && count < k) {
            count++;
            curr = curr->next;
        }

        if (curr) {
            ListNode* next = curr->next;
            if (curr->next)
                curr->next = nullptr;
            reverse(head);
            head->next = reverseKGroup(next, k);
            return curr;
        }

        return head;
    }
};