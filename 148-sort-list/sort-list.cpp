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
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* c = new ListNode(100);
        ListNode* tc = c;
        while(a!= NULL && b!= NULL){
            if(a->val<=b->val){

                tc->next = a;
                a = a->next;
                tc= tc->next;
            }
            else{
                 
                tc->next = b;
                b = b->next;
                tc= tc->next;
            }
        }
            if(a==NULL)    tc->next= b;
            
            else    tc->next = a;
            
            return c->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!= NULL && fast->next->next!= NULL){//for even for odd
            slow= slow->next;
            fast = fast->next->next;
            }
            ListNode * a = head;
            ListNode * b = slow->next;
            slow -> next = NULL;
            a = sortList(a);
            b = sortList(b);
            ListNode * c = merge(a,b);
            return c;
    }
};