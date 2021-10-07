class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        size_t len = temperatures.size();
        vector<int> res(len);

        for (int i = 0; i < len; ++i){
            auto t = temperatures[i];
            if (s.empty() || t <= temperatures[s.top()]){
                s.push(i);
            } else {
                while (!s.empty() && t > temperatures[s.top()]){
                    int pos = s.top();
                    res[pos] = i - pos;
                    s.pop();
                }
                s.push(i);
            }
        }
        return res;
    }
};