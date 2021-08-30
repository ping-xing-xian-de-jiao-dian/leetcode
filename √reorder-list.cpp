class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* p = head;
        ListNode* newHead = NULL;
        while (p){
            ListNode* q = p->next;
            p->next = newHead;
            newHead = p;
            p = q;
        }
        return newHead;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // 找到中点后，反转后面的
        ListNode* half = slow->next;
        slow->next = NULL;
        half = reverse(half);
        // 反转完后面的后，合并链表(half和head)
        while (head && half){
            ListNode* temp = head;
            head = head->next;
            temp->next = half;
            half = half->next;
            temp->next->next = head;
        }
    }
};