class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const size_t len = gas.size();
        if (len == 1) return gas[0] - cost[0] >= 0 ? 0 : - 1;
        for (int i = 0; i < len; ++i) gas[i] -= cost[i];
        if (len == 2){
            if (gas[0] + gas[1] >= 0){
                if (gas[0] >= 0) return 0;
                return 1;
            } return - 1;
        }
        int sum = 0, start = 0, maxi = 0, end = 0, maxStart = - 1, maxEnd = - 1;
        while (1){
            if (sum < 0){
                sum = 0; start = end;
            } else {
                sum += gas[end % len];
                end++;
                if (sum > maxi){
                    maxi = sum;
                    maxStart = start;
                    maxEnd = end;
                }
            }
            if (end >= 2 * len - 2) break;
        }
        cout << maxStart << ' ' << maxEnd << ' ' << maxi << endl;
        if (maxStart == - 1) return - 1;
        for (int i = maxEnd % len; i != maxStart; i = (i + 1) % len){
            maxi += gas[i];
            if (maxi < 0) return - 1;
        }
        return maxStart;
    }
};