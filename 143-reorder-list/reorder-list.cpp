class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode *prev = NULL, *curr = head, *next = head;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!= NULL && fast->next->next!= NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* b = reverseList(slow->next);
        ListNode*a = head;
        slow->next = NULL;
        ListNode * c= new ListNode(1);
        ListNode* tempC = c;
        ListNode* tempA = a;
        ListNode* tempB = b;
        while(tempA && tempB){
            tempC->next = tempA;
            tempA = tempA->next;
            tempC = tempC->next;

            tempC->next = tempB;
            tempB = tempB->next;
            tempC = tempC->next;
        }
        tempC->next = tempA;
        head =  c->next;
    }
};