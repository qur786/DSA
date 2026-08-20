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
        if (!head || !head->next)
            return head;
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
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* curr = dummy;
        int count = -1;
        ListNode *prevLeft = nullptr, *prevRight = nullptr;

        while (curr) {
            count++;
            if (count == left - 1)
                prevLeft = curr;
            if (count == right) {
                prevRight = curr;
                break;
            }
            curr = curr->next;
        }

        ListNode* subList = prevLeft->next;
        ListNode* postRight = prevRight->next;
        prevRight->next = nullptr;
        prevLeft->next = nullptr;
        ListNode* reverseredSublist = reverse(subList);
        prevLeft->next = reverseredSublist;
        subList->next = postRight;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};