class DetectSquares {
private:
    map<int, map<int, int>> axis;
    
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        axis[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int cou = 0;
        int xx = point[0], yy = point[1];
        for (auto [y, count] : axis[xx]){
            // 需要不同点
            if (y == yy) continue;
            int a, b;
            if ((a = axis[xx + abs(y - yy)][yy]) != 0 &&
                    (b = axis[xx + abs(y - yy)][y]) != 0){
                cou += a * b * count;
            }
            if ((a = axis[xx - abs(y - yy)][yy]) != 0 &&
                     (b = axis[xx - abs(y - yy)][y]) != 0){
                cou += a * b * count;
            }
        }
        return cou;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */