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
        

        if(l1==l2){
            if(t1==t2) return t2;
            else{ 
            while (t2 != NULL){
                if(t1->next == t2->next) return t2->next;
                else{
                    t1 = t1->next;
                    t2 = t2->next;
                }
            }
            }
            return NULL;
        }
        else if(l2<l1) {
            d = l1-l2;
            for(int i =0; i < d; i++){
                t1= t1->next;
            }
            if(t1==t2) return t2;
            while (t2 != NULL){
                if(t1->next == t2->next) return t2->next;
                else{
                    t1 = t1->next;
                    t2 = t2->next;
                }
            }
            return NULL;
        }
    
           else if(l1<l2) {
            d = l2-l1;
            for(int i =0; i < d; i++){
                t2= t2->next;
            }
            if(t1==t2) return t2;
            while (t1 != NULL){
                if(t1->next == t2->next) return t1->next;
                else{
                    t1 = t1->next;
                    t2 = t2->next;
                }
            }
            return NULL;
        }
        return NULL;
    }    

    
};