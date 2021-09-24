class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        n -= 1;
        int a = 0, b = 1, c;
        while (n--){
            c = a + b;
            a = b; b = c;
        }
        return c;
    }
};