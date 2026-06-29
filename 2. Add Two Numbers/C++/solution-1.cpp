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

        ListNode* resultNode = new ListNode(0);
        ListNode* curr = resultNode;
        int carry = 0;
        while (l1 && l2) {
            int sum = carry + l1->val + l2->val;
            carry = sum / 10;
            sum %= 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int sum = carry + l1->val;
            carry = sum / 10;
            sum %= 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            l1 = l1->next;
        }
        while (l2) {
            int sum = carry + l2->val;
            carry = sum / 10;
            sum %= 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            l2 = l2->next;
        }
        if (carry > 0)
            curr->next = new ListNode(carry);

        ListNode* result = resultNode->next;

        delete resultNode;

        return result;
    }
};