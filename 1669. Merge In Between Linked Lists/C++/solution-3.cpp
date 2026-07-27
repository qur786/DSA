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
        ListNode* dummy = new ListNode();
        dummy->next = list1;
        ListNode *prev = nullptr, *curr = dummy;
        ListNode *prevStart = nullptr, *postEnd = nullptr;
        int nodeCount = -1;
        while (list1) {
            prev = curr;
            curr = curr->next;
            nodeCount++;
            if (nodeCount == a)
                prevStart = prev;
            if (nodeCount == b) {
                postEnd = curr->next;
                break;
            }
            list1 = list1->next;
        }

        prevStart->next = list2;
        while (list2->next) {
            list2 = list2->next;
        }
        list2->next = postEnd;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};