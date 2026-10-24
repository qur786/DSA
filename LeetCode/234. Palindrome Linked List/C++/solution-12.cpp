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
private:
    ListNode* masterHead = nullptr;
    bool solve(ListNode* head) {
        if (!head)
            return true;

        if (!solve(head->next))
            return false;

        if (!masterHead)
            return true;

        if (masterHead->val != head->val)
            return false;

        if (masterHead == head || masterHead->next == head) {
            masterHead = nullptr;

            return true;
        }

        masterHead = masterHead->next;

        return true;
    }

public:
    bool isPalindrome(ListNode* head) {
        masterHead = head;
        return solve(head);
    }
};