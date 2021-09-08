class Solution {
private:
    size_t len;
    vector<string> res;

public:
    // static int cmp(vector<string> a, vector<string> b){
    //     for (int i = 0; i < a.size(); ++i){
    //         for (int j = 0; j < a[i].length(); ++j){
    //             if (a[i][j] > b[i][j]) return 1;
    //             if (a[i][j] < b[i][j]) return - 1;
    //         }
    //     }
    //     return 0;
    // }

    int vis[301] = {0};
    int flag = 1;
    void dfs(vector<vector<string>>& tickets, string start, int count){
        if (count == len){
            flag = 0;
            res.emplace_back(start);
            return;
        }
        for (int i = 0; i < len; ++i){
            if (tickets[i][0] == start && vis[i] == 0){
                vis[i] = 1;
                res.emplace_back(start);
                dfs(tickets, tickets[i][1], count + 1);
                if (flag == 0) return;
                res.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        len = tickets.size();
        sort(tickets.begin(), tickets.end(), cmp);
        for (auto a : tickets) cout << a[0] << ' ' << a[1] << endl;
        dfs(tickets, "JFK", 0);
        return res;
    }
};