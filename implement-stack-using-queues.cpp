class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (q2.empty()) swap(q1, q2);
        q1.push(x);
        while (!q2.empty()){
            int temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};