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
        ListNode* curr = dummy;
        int itr = -1;
        ListNode *leftEnd = nullptr, *middleEnd = nullptr;

        while (curr && itr <= b) {
            if (itr == (a - 1)) {
                leftEnd = curr;
            }
            if (itr == b) {
                middleEnd = curr;
            }
            itr++;
            curr = curr->next;
        }

        leftEnd->next = list2;
        ListNode* rightStart = middleEnd->next;
        middleEnd->next = nullptr;

        ListNode *prev = nullptr, *curr2 = list2;
        while (curr2) {
            prev = curr2;
            curr2 = curr2->next;
        }

        prev->next = rightStart;

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};