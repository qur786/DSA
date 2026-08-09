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
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *next = head;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    void merge(ListNode* list1, ListNode* list2) {
        ListNode* curr = list1;
        while (list2) {
            ListNode* tempList2 = curr->next;
            curr->next = list2;
            curr = curr->next;
            list2 = tempList2;
        }
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        ListNode *slow = head, *fast = head->next->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middle = slow->next;
        slow->next = nullptr;
        middle = reverse(middle);
        merge(head, middle);
    }
};