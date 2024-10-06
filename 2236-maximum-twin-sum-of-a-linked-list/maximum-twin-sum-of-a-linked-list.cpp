#include <climits> // For INT_MIN

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *next = head;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode *s = head, *f = head;
        while(f->next != NULL && f->next->next != NULL){
            s = s->next;
            f = f->next->next;
        }
        ListNode* b = reverseList(s->next);
        ListNode* tb = b;
        ListNode* ta = head;
        s->next = NULL;
        int msum = INT_MIN, sum = 0;
        while(ta && tb){
            sum = (ta->val) + (tb->val);
            if(sum > msum) msum = sum;
            ta = ta->next;
            tb = tb->next;
        }
        return msum;
    }
};
