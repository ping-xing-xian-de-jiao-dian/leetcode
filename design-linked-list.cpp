class MyLinkedList {
private:
    int* head;
    int* tail;

public:
    MyLinkedList() {
        head = tail = new int[2000];
        head = tail = head + 1000;
    }
    
    int get(int index) {
        if (index < 0 || index >= tail - head) return -1;
        return *(head + index);
    }
    
    void addAtHead(int val) {
        --head;
        *head = val;
    }
    
    void addAtTail(int val) {
        *tail = val;
        ++tail;
    }
    
    void addAtIndex(int index, int val) {
        if (index > tail - head) return;
        if (index < 0){
            addAtHead(val);
            return;
        }
        int* temp = tail - 1;
        while (temp != head + index - 1){
            *(temp + 1) = *temp;
            --temp;
        }
        *(temp + 1) = val;
        ++tail;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= tail - head) return;
        int* temp = head + index;
        while (temp != tail - 1){
            *(temp) = *(temp + 1);
            ++temp;
        }
        --tail;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */