class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;        ListNode* t2 = headB;
        int l1=0 ,l2 = 0;
        while(t1!=NULL){
            l1++;
            t1 = t1->next;
        }
        while(t2!=NULL){
            l2++;
            t2 = t2->next;
        }
        t1 = headA;
        t2 = headB;
        int d =0;
        if(l2<l1) {
            d = l1-l2;
            for(int i =0; i < d; i++){
                t1= t1->next;
            }
            while(t1!=t2){
                    t1 = t1->next;
                    t2 = t2->next;
            }
                return t1;

        }
    
           else {
            d = l2-l1;
            for(int i =0; i < d; i++){
                t2= t2->next;
            }
            while(t1!=t2){
                    t1 = t1->next;
                    t2 = t2->next;
                
            }
            return t1;
        }
        
    }    

    
};