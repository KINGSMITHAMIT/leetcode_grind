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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(l==r) return head;
        ListNode *a= NULL, *b = NULL, *c = NULL, *d = NULL, * temp= head;
        int n = 1;
        while(temp){
            if(n==l-1) a = temp;
            if(n==l)  b= temp;
            if(n==r) c = temp;
            if(n==r+1) d = temp;
            temp = temp->next;
            n++;
        }
        if(a) a->next + NULL;
        c->next = NULL;
        c = reverseList(b);
        if(a) a->next = c;
        b->next =d;
        if(a) return head;
        return c;

        return head;  
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp = head;
        int gap = 1;
        while(temp && temp->next){
            int remLen = 0;
            ListNode *t = temp->next;
            for(int i = 1; i<= gap+1 && t!= NULL; i++){
                t = t->next;
                remLen++;
            }
            if(remLen<gap+1) gap = remLen-1;
            if(gap%2!=0) reverseBetween (temp, 2, 2+gap);
            gap++;
            for(int i = 1; temp!= NULL && i<= gap;i++){
                temp = temp->next;
            }
        }
        return head;
    }
};