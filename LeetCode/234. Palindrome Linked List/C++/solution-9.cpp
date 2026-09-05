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
    bool checkPalindrom(ListNode* head) {
        if (!head)
            return true;

        if (!checkPalindrom(head->next))
            return false;

        if (!masterHead)
            return true;

        if (masterHead == head || masterHead == head->next) {
            masterHead = nullptr;
            return true;
        }

        if (masterHead->val != head->val)
            return false;

        masterHead = masterHead->next;

        return true;
    }

public:
    bool isPalindrome(ListNode* head) {
        this->masterHead = head;
        return checkPalindrom(head);
    }
};