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
    ListNode* findMiddle(ListNode* head) {
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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if (list1)
            curr->next = list1;
        if (list2)
            curr->next = list2;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* middle = findMiddle(head);
        ListNode* list1 = mergeSort(head);
        ListNode* list2 = mergeSort(middle);
        ListNode* result = merge(list1, list2);
        return result;
    }
    ListNode* sortList(ListNode* head) { return mergeSort(head); }
};