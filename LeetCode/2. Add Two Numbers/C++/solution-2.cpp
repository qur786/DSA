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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (l1 && l2) {
            curr->next = new ListNode(0);
            curr = curr->next;
            int sum = carry + l1->val + l2->val;
            carry = sum / 10;
            curr->val = sum % 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            curr->next = new ListNode(0);
            curr = curr->next;
            int sum = carry + l1->val;
            carry = sum / 10;
            curr->val = sum % 10;
            l1 = l1->next;
        }
        while (l2) {
            curr->next = new ListNode(0);
            curr = curr->next;
            int sum = carry + l2->val;
            carry = sum / 10;
            curr->val = sum % 10;
            l2 = l2->next;
        }

        if (carry > 0)
            curr->next = new ListNode(carry);

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};