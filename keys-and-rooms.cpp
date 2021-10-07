class Solution {
public:
    int cou = 0;
    int vis[1000] = {0};
    void dfs(vector<vector<int>>& rooms, int pos){
        vis[pos] = 1; ++cou;
        for (int i = 0; i < rooms[pos].size(); ++i){
            if (!vis[rooms[pos][i]]){
                vis[rooms[pos][i]] = 1;
                dfs(rooms, rooms[pos][i]);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(rooms, 0);
        size_t len = rooms.size();
        return len == cou;
    }
};