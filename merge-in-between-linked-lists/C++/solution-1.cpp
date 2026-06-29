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
        ListNode* dummyNode = new ListNode();
        dummyNode->next = list1;
        ListNode* l2End = list2;

        while (l2End->next)
            l2End = l2End->next;

        ListNode *l1StartPrev = dummyNode, *l1EndAfter = dummyNode;
        int countStartPrev = 1, countEndAfter = 1;
        while (countStartPrev <= a) {
            countStartPrev++;
            l1StartPrev = l1StartPrev->next;
        }
        while (countEndAfter <= b) {
            countEndAfter++;
            l1EndAfter = l1EndAfter->next;
        }
        l1EndAfter = l1EndAfter->next->next;

        l1StartPrev->next = list2;
        l2End->next = l1EndAfter;

        list1 = dummyNode->next;
        delete dummyNode;

        return list1;
    }
};