class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* slow = list1;
        ListNode* fast = list1;
        ListNode* ta = list2;
        ListNode* tb = list2;

        // Find the last node of list2
        while (tb->next) {
            tb = tb->next;
        }

        // Move fast pointer to the b-th node
        for (int i = 0; i <= b; i++) {
            fast = fast->next;
        }

        // Move slow pointer to the (a-1)-th node
        for (int i = 1; i < a; i++) {
            slow = slow->next;
        }

        // Connect the (a-1)-th node to the head of list2
        slow->next = ta;

        // Connect the last node of list2 to the (b+1)-th node
        tb->next = fast;

        return list1;
    }
};
