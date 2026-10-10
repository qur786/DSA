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
    ListNode* masterIndex = nullptr;
    bool checkPalindrome(ListNode* head) {
        if (!head)
            return true;

        if (!checkPalindrome(head->next))
            return false;

        if (!masterIndex)
            return true;

        if (masterIndex == head || masterIndex == head->next) {
            masterIndex = nullptr;
            return true;
        }

        if (masterIndex->val != head->val)
            return false;

        masterIndex = masterIndex->next;

        return true;
    }

public:
    bool isPalindrome(ListNode* head) {
        masterIndex = head;
        return checkPalindrome(head);
    }
};