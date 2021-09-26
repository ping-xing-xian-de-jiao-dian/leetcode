class Solution {
public:
    int getSum(int a, int b) {
        int c = 1;
        while (c){
            c = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = c;
        } 
        return a ^ b;
    }
};