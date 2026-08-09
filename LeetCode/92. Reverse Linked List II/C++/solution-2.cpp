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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next)
            return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* curr = dummy;
        ListNode *prev = nullptr, *next = nullptr;
        int l = 0, r = -1;

        while (curr) {
            l++;
            r++;
            if (l == left)
                prev = curr;
            if (r == right)
                next = curr;
            curr = curr->next;
        }
        ListNode* rightPart = next->next;
        next->next = nullptr;
        ListNode* subListHead = prev->next;
        ListNode* leftPart = prev;
        leftPart->next = nullptr;
        leftPart->next = reverse(subListHead);
        subListHead->next = rightPart;

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};