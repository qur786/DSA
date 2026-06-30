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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1)
            curr->next = l1;
        if (l2)
            curr->next = l2;

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
    ListNode* getMiddle(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head->next->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middle = slow->next;
        slow->next = nullptr;

        return middle;
    }
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* middle = getMiddle(head);
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(middle);
        ListNode* result = merge(l1, l2);

        return result;
    }
};