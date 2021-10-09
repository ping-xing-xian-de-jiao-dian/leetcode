class SummaryRanges {
private:
    vector<int> nums;
    int maxi;

public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        nums.resize(10002);
        maxi = -1;
    }
    
    void addNum(int val) {
        nums[val] = 1;
        maxi = max(maxi, val);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        int flag = 0, start, end;
        for (int i = 0; i <= maxi + 1; ++i){
            if (nums[i]){
                if (!flag){
                    start = end = i;
                    flag = 1;
                }
            } else {
                if (flag){
                    end = i - 1;
                    vector<int> temp = {start, end};
                    res.emplace_back(temp);
                    flag = 0;
                
                }
            }
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */