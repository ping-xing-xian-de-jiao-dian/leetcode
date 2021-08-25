#include<iostream>
using namespace std;

class Solution {
public:
    int vis[16];
    vector<vector<int>> res;
    vector<int> temp;
    int n;
    void dfs(vector<vector<int>>& graph, int start){
        if (start == n - 1){
            res.emplace_back(temp);
            return;
        }
        for (const auto& des : graph[start]){
            if (!vis[des]){
                vis[des] = 1;
                temp.emplace_back(des);
                dfs(graph, des);
                temp.pop_back();
                vis[des] = 0;
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        memset(vis, 0, sizeof(vis));
        temp.emplace_back(0);
        dfs(graph, 0);
        return res;
    }
};