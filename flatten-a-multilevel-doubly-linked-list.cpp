/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        Node* temp = head;
        stack<Node*> s;
        int flag = 1;
        while (!s.empty() || flag){
            flag = 0;
            while (temp->next && !temp->child) temp = temp->next;\
            if (temp->child){
                s.push(temp);
                s.push(temp->next);
                temp = temp->child;
            } else if (!temp->next){
                if (!s.empty()){
                    Node* post = s.top();
                    temp->next = post;
                    if (post) temp->next->prev = temp;
                    temp->child = nullptr;
                    s.pop();

                    Node* pre = s.top();
                    pre->next = pre->child;
                    pre->next->prev = pre;
                    pre->child = nullptr;
                    s.pop();
                }
            }
        }
        return head;
    }
};