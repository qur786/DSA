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
        ListNode *curr = head, *prev = nullptr, *next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = k;
        ListNode* curr = head;
        while (curr && n > 1) {
            curr = curr->next;
            n--;
        }

        if (!curr)
            return head;

        ListNode* next = curr->next;
        curr->next = nullptr;
        reverse(head);
        head->next = reverseKGroup(next, k);

        return curr;
    }
};