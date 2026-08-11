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
        if (!head || !head->next)
            return head;
        ListNode *prev = nullptr, *curr = head, *next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    void merge(ListNode* list1, ListNode* list2) {
        while (list2) {
            ListNode* temp = list1->next;
            list1->next = list2;
            list1 = list1->next;
            list2 = temp;
        }
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        ListNode* middle = splitMiddle(head);
        middle = reverse(middle);
        merge(head, middle);
    }
};