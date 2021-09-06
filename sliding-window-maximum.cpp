// priority_queue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int nowLe = 0, nowRi = k - 1;
        size_t len = nums.size();
        vector<int> res;
        priority_queue<vector<int>, vector<vector<int>>, less<vector<int>>> que;
        for (int i = 0; i < k; ++i){
            vector<int> temp = {nums[i], i};
            que.push(temp);
        }
        while (!que.empty()){
            if (que.top()[1] >= nowLe && que.top()[1] <= nowRi){
                res.emplace_back(que.top()[0]);
                ++nowLe; ++nowRi;
                if (nowRi == len) break;
                vector<int> temp = {nums[nowRi], nowRi};
                que.push(temp);
            } else {
                que.pop();
            }
        }
        return res;
    }
};


// monotone queue <--> deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 看到这种问题可以想到单调栈，但是这里又需要对最前端的数据操作，因此需要队列
        // 由此引出了“单调队列”！(吊打单调栈？)
        // deque表示双端队列
        size_t len = nums.size();
        deque<int> que;
        vector<int> res;
        // 初始化（单调递减，因为位于左边且值还比新来的小的已经没有利用价值了）
        // 但是只能存下标，因为存值的话就不知道遍历到哪里了
        for (int i = 0; i < len; ++i){
            while (!que.empty() && nums[i] > nums[que.back()]){
                que.pop_back();
            }
            que.push_back(i);
            while (que.front() <= i - k){
                que.pop_front();
            }
            if (i < k - 1) continue;
            res.emplace_back(nums[que.front()]);
        }
        return res;
    }
};