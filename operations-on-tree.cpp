class LockingTree {
private:
    vector<int> p;
    vector<vector<int>> isLock;
    int len;
    vector<vector<int>> sons;
    int flag;
    
public:
    LockingTree(vector<int>& parent) {
        p = parent;
        len = parent.size();
        isLock.resize(len, vector<int>(2, 0));
        
        sons.resize(len, vector<int>());
        for (int i = 0 ; i < len; ++i){
            if (parent[i] == - 1) continue;
            sons[parent[i]].emplace_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (isLock[num][0] == 0){
            isLock[num][0] = 1;
            isLock[num][1] = user;
            return 1;
        }
        return 0;
    }
    
    bool unlock(int num, int user, int niubi = 0) {
        if (isLock[num][0] == 0) return 0;
        if (niubi == 0 && isLock[num][1] != user) return 0;
        isLock[num][0] = 0;
        isLock[num][1] = 0;
        return 1;
    }
    
    // 判断sons[num]中有上锁
    void dfs(int num, int user){
        if (isLock[num][0] == 1){
            flag = 1;
            unlock(num, user, 1);
        }
        for (int i = 0; i < sons[num].size(); ++i){
            dfs(sons[num][i], user);
        }
    }
    
    bool upgrade(int num, int user) {
        if (isLock[num][0] == 1) return 0;
        int a = num;
        
        while (num != - 1){
            if (isLock[num][0] == 1) return 0;
            num = p[num];
        }
        
        flag = 0;
        dfs(a, user);
        if (flag == 0) return 0;
        
        
        lock(a, user);
        return 1;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */