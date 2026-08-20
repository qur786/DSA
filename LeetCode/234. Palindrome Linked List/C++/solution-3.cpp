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
    ListNode* splitMiddle(ListNode* head) {
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

public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode* middle = splitMiddle(head);
        ListNode* reverseMiddle = reverse(middle);

        while (head && reverseMiddle) {
            if (head->val != reverseMiddle->val)
                return false;
            head = head->next;
            reverseMiddle = reverseMiddle->next;
        }

        return true;
    }
};