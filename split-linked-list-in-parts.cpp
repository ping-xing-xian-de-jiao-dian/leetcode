/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while (temp) temp = temp->next, ++len;
        vector<int> cou(k, len / k);
        int rest = len % k;
        int i = 0;
        while (rest--) ++cou[i], ++i;

        vector<ListNode*> res;
        temp = head;
        for (int i = 0; i < k; ++i){
            ListNode* re = temp, * r = re;
            for (int j = 0; j < cou[i] - 1; ++j){
                temp = temp->next;
                r = r->next;
            }
            if (temp) temp = temp->next;
            if (r) r->next = nullptr;
            res.emplace_back(re);
        }
        return res;
    }
};