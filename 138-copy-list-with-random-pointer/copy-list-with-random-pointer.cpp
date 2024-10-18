/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // step ->1 create a deep copy without random pointer
        Node *dummy = new Node(1), *tempC = dummy, *temp = head;
        while(temp){
            Node* a =  new Node(temp->val);
            tempC->next = a;
            tempC = tempC ->next;
            temp = temp->next;
        }
        Node* duplicate = dummy->next;
        //step 2 -> alternate connections
        Node *a = head, *b = duplicate;
        dummy = new Node(19);
        Node *tempD = dummy;
        while(a){
            tempD ->next = a;
            a = a->next;
            tempD = tempD->next;
            tempD->next = b;
            b = b->next;
            tempD = tempD->next;
        }
        dummy = dummy->next;
        //step3 -> assigning random pointers
        Node* t1 = head; // t1 will travers in the original list
        while(t1){
            Node * t2 = t1->next;
            if(t1->random) t2->random = t1->random->next;
            t1 = t1->next->next;
        } 
        //step4-> removing the connection (separate)
        Node* d1 = new Node(03);
        Node* d2 = new Node(23);
        t1 = d1;
        Node* t2 = d2;
        Node* t = dummy;
        while(t){
            t1 ->next = t;
            t = t->next;
            t1 = t1->next;
            t2 ->next = t;
            t = t->next;
            t2 = t2->next;
        }
        t1 ->next = NULL;
        t2 ->next = NULL;
        d1 = d1 ->next;     // original with random
        d2 = d2 ->next;     // duplicate with random
        return d2;
    }
};