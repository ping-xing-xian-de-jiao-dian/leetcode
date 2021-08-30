class Solution {
public:
    int cal(int n){
        int sum = 0;
        while (n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    // 哈希集
    bool isHappy(int n) {
        set<int> s;
        while (1){
            n = cal(n);
            if (n == 1) return 1;
            if (s.find(n) != s.end()) return 0;
            s.insert(n);
        }
    }
    // 快慢指针
    bool isHappy(int n) {
        int n1 = n, n2 = n;
        while (1){
            n1 = cal(n1); n2 = cal(cal(n2));
            if (n1 == 1 || n2 == 1) return 1;
            if (n1 == n2) return 0;
        }
    }
};