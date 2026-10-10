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
        int i = 0;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr && i < k) {
            prev = curr;
            curr = curr->next;
            i += 1;
        }

        if (i == k) {
            prev->next = nullptr;
            reverse(head);
            head->next = reverseKGroup(curr, k);
            return prev;
        }

        return head;
    }
};