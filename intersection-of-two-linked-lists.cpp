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