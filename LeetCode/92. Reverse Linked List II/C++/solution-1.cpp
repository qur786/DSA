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
        ListNode *curr = head, *prev = nullptr, *next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        if (!head || !head->next)
            return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode *leftEnd = dummy, *rightHead = head;

        while (left > 1) {
            leftEnd = leftEnd->next;
            left--;
        }
        while (right > 1) {
            rightHead = rightHead->next;
            right--;
        }
        ListNode* subListNode = leftEnd->next;
        leftEnd->next = nullptr;

        ListNode* temp = rightHead->next;
        rightHead->next = nullptr;
        rightHead = temp;

        ListNode* reverseHead = reverse(subListNode);

        leftEnd->next = reverseHead;

        while (reverseHead->next)
            reverseHead = reverseHead->next;
        reverseHead->next = rightHead;

        head = dummy->next;
        delete dummy;
        return head;
    }
};