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
        ListNode *slow = head, *fast = head;

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
        ListNode* medium = findMedium(head);
        medium = reverse(medium);
        ListNode* dummy = new ListNode();
        ListNode *curr = head, *result = dummy;
        int count = 0;
        while (curr && medium) {
            if (count % 2 == 0) {
                result->next = curr;
                curr = curr->next;
            } else {
                result->next = medium;
                medium = medium->next;
            }
            result = result->next;
            count++;
        }

        head = dummy->next;
        delete dummy;
    }
};