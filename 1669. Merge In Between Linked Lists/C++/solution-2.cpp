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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* l2End = list2;

        while (l2End->next)
            l2End = l2End->next;

        ListNode* dummy = new ListNode(0);
        dummy->next = list1;

        ListNode *l1Start = dummy, *l1End = dummy->next->next;
        int countStart = 1, countEnd = 1;
        while (countStart <= a) {
            countStart++;
            l1Start = l1Start->next;
        }
        while (countEnd <= b) {
            countEnd++;
            l1End = l1End->next;
        }

        l1Start->next = list2;
        l2End->next = l1End;

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};