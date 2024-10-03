class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* ot = odd;
        ListNode* et = even;
        ListNode* temp = head;
        int count = 1;

        while (temp != NULL) {
            if (count % 2 == 0) {
                et->next = temp;
                et = et->next;
            } else {
                ot->next = temp;
                ot = ot->next;
            }
            temp = temp->next;
            count++;
        }

        et->next = nullptr; // End the even list
        ot->next = even->next; // Connect odd list to even list

        return odd->next; // Return the head of the new list
    }
};
