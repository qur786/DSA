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
    ListNode* findMedium(ListNode* head) {
        ListNode *slow = head, *fast = head->next->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        ListNode* medium = findMedium(head);
        ListNode* newList = reverse(medium->next);
        medium->next = nullptr;
        ListNode* curr = head;
        while (curr && newList) {
            ListNode* temp = curr->next;
            curr->next = newList;
            curr = curr->next;
            newList = temp;
        }
    }
};