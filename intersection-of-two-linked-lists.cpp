class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> setA;
        while (headA){
            setA.insert(headA);
            headA = headA->next;
        }
        while (headB){
            if (setA.find(headB) != setA.end()) return headB;
            headB = headB->next;
        }
        return NULL;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode* pa = headA, * pb = headB;
        while (pa != pb){
            if (!pa) pa = headB; else pa = pa->next;
            if (!pb) pb = headA; else pb = pb->next;
        }
        return pa;
    }
};