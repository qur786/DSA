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
    bool checkPalindrome(ListNode* head) {
        if (!head)
            return true;

        bool res = checkPalindrome(head->next);

        if (!res || masterHead->val != head->val)
            return false;

        masterHead = masterHead->next;

        return true;
    }

public:
    bool isPalindrome(ListNode* head) {
        masterHead = head;
        return checkPalindrome(head);
    }
};