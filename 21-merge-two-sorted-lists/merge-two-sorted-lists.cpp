class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode * ta = a;
        ListNode* tb = b;
        ListNode* c = new ListNode(100);
        ListNode* tc = c;
        while(ta!= NULL && tb!= NULL){
            if(ta->val<=tb->val){
                ListNode* t = new ListNode(ta->val);
                tc->next = t;
                tc = t;
                ta= ta->next;
            }
            else{
                 ListNode* t = new ListNode(tb->val);
                tc->next = t;
                tc = t;
                tb= tb->next;
            }
        }
            if(ta==NULL){
                tc->next= tb;
            }
            else{
                tc->next = ta;
            }
            return c->next;
    }
};