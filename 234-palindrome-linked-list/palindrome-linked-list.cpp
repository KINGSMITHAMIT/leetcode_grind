class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *next = head;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Create a deep copy of the list
        ListNode* c = new ListNode(0); // Dummy node
        ListNode* temp = head;
        ListNode* tempC = c;
        while (temp) {
            ListNode* node = new ListNode(temp->val);
            tempC->next = node;
            temp = temp->next;
            tempC = tempC->next;
        }
        c = c->next; // Skip the dummy node

        // Reverse the copied list
        c = reverseList(c);

        // Compare the original list with the reversed copy
        ListNode* a = head;
        ListNode* b = c;
        while (a && b) {
            if (a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }

        return true;
    }
};
