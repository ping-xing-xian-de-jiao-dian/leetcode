class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* p = head;
        head = nullptr;
        while (p){
            ListNode* q = p->next;
            p->next = head;
            head = p;
            p = q;
        }
        return head;
    }

    bool isPalindrome(ListNode* head) {
        // 取中点，反转，比较
        ListNode* slow = head, * fast = head;
        while (fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        mid = reverse(mid);
        while (mid){
            if (mid->val != head->val) return 0;
            mid = mid->next;
            head = head->next;
        }
        return 1;
    }
};