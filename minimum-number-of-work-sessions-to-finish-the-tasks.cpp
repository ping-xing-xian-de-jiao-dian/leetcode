class Solution {
public:
    int calculate(vector<int>& tasks, int sessionTime){
        int time11 = 0, count = 1;
        for (int task : tasks){
            if (time11 + task <= sessionTime){
                time11 += task;
            } else {
                time11 = task;
                count++;
            }
        }
        return count;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        int mini = INT_MAX;
        for (int i = 0; i < 2000; ++i){
            random_shuffle(begin(tasks), end(tasks));
            mini = min(mini, calculate(tasks, sessionTime));
        }
        return mini;
    }
};