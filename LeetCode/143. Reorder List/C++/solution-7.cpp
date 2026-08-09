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
    ListNode* splitMiddle(ListNode* head) {
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
    void merge(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2)
            return;
        while (l2) {
            ListNode* temp = l1->next;
            l1->next = l2;
            l1 = l1->next;
            l2 = temp;
        }
    }

public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        ListNode* middle = splitMiddle(head);
        middle = reverse(middle);

        merge(head, middle);
    }
};