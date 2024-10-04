class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *next = head;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!= NULL && fast->next->next!= NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow is at the left middle/middle
        ListNode * newHead = reverseList(slow->next);
        ListNode* a = head;
        ListNode* b = newHead;
        while (a && b) {
            if (a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }

        return true;
    }
};
