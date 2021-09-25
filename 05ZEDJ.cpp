#define ll long long

class Solution {
public:
    map<ll, vector<ll>> mp;
    vector<int> volunteerDeployment(vector<int>& finalCnt, long long totalNum, vector<vector<int>>& edges, vector<vector<int>>& plans) {
        for (auto e : edges) {
            mp[e[0]].emplace_back(e[1]);
            mp[e[1]].emplace_back(e[0]);
        }

        vector<int> nums;
        nums.emplace_back(0);
        for (int a : finalCnt) nums.emplace_back(a);
        int len = nums.size();

        // 系数和截距
        vector<vector<ll>> time_p;
        time_p.resize(len, vector<ll>(2, 0));
        int pos = 0;
        for (auto& p : time_p) {
            p[1] = nums[pos++];
        }
        time_p[0][0] = 1;
        
        for (int i = plans.size() - 1; i >= 0; --i) {
            auto plan = plans[i];
            if (plan[0] == 1) {
                time_p[plan[1]][0] *= 2;
                time_p[plan[1]][1] *= 2;
            }
            // 相邻都减去
            else if (plan[0] == 2) {
                for (auto temp : mp[plan[1]]) {
                    time_p[temp][0] -= time_p[plan[1]][0];
                    time_p[temp][1] -= time_p[plan[1]][1];
                }
            }
            else {
                for (auto temp : mp[plan[1]]) {
                    time_p[temp][0] += time_p[plan[1]][0];
                    time_p[temp][1] += time_p[plan[1]][1];
                }
            }
        }
        ll sum = 0;
        for (auto a : time_p) totalNum -= (ll)a[1], sum += (ll)a[0];
        if (sum == 0) sum = 1;
        nums[0] = totalNum / sum;

        for (int i = plans.size() - 1; i >= 0; --i) {
            auto plan = plans[i];
            if (plan[0] == 1) {
                nums[plan[1]] <<= 1;
            }
            // 相邻都减去
            else if (plan[0] == 2) {
                for (auto temp : mp[plan[1]]) {
                    nums[temp] -= nums[plan[1]];
                }
            }
            else {
                for (auto temp : mp[plan[1]]) {
                    nums[temp] += nums[plan[1]];
                }
            }
        }

        return nums;
    }
};