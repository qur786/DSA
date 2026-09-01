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
            return nullptr;
        int count = 1;
        ListNode* curr = head;

        while (count < k && curr) {
            count++;
            curr = curr->next;
        }

        if (curr) {
            ListNode* next = curr->next;
            curr->next = nullptr;
            reverse(head);
            if (next)
                head->next = reverseKGroup(next, k);
            return curr;
        }

        return head;
    }
};