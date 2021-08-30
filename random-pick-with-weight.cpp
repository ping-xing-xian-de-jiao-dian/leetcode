class Solution {
private:
    int sum;
    vector<double> weight;

public:
    Solution(vector<int>& w) {
        srand((unsigned)time(0));
        sum = 0;
        weight = w;
        for (int temp : w) sum += temp;
        for (int temp : w) weight.push_back(temp * 1. / sum * 100);
        for (int i = 1; i < w.size(); ++i) weight[i] += weight[i - 1];
    }
    
    int pickIndex() {
        int ran = rand() % 101;
        for (int i = 0; i < weight.size(); ++i){
            if (ran <= weight[i]) return i;
        }
        return 0;
    }
};