class MedianFinder {
private:
    // 升序队列，存的是大的值（右边的）
    priority_queue<int, vector<int>, greater<int>> maxInQueue;
    // 降序队列，存的是小的值（左边的）（头最大）
    priority_queue<int, vector<int>, less<int>> minInQueue;
    int len;

public:
    /** initialize your data structure here. */
    MedianFinder() {
        len = 0;
    }
    
    void addNum(int num) {
        ++len;
        int left = minInQueue.size(), right = maxInQueue.size();
        if (left == right){
            if (left == 0){
                minInQueue.push(num);
            } else if (num >= maxInQueue.top()){
                int temp = maxInQueue.top();
                maxInQueue.pop();
                minInQueue.push(temp);
                maxInQueue.push(num);
            } else {
                minInQueue.push(num);
            }
        } else {
            if (num >= minInQueue.top()) maxInQueue.push(num);
            else {
                int temp = minInQueue.top();
                minInQueue.pop();
                maxInQueue.push(temp);
                minInQueue.push(num);
            }
        }
    }
    
    double findMedian() {
        if (len & 1) return minInQueue.top();
        return (minInQueue.top() + maxInQueue.top()) / 2.;
    }
};