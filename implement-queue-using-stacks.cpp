class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;

public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (st2.empty()){
            while (!st1.empty()){
                int temp = st1.top();
                st1.pop();
                st2.push(temp);
            }
        }
        int temp = st2.top();
        st2.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if (st2.empty()){
            while (!st1.empty()){
                int temp = st1.top();
                st1.pop();
                st2.push(temp);
            }
        }
        int temp = st2.top();
        return temp;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }
};
