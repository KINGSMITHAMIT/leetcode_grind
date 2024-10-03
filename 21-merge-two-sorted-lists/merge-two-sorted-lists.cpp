class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
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
};