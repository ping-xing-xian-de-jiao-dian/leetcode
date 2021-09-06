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