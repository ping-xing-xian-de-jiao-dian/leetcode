class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        while (fast && k--) fast = fast->next;
        ListNode* slow = head;
        while (fast){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};