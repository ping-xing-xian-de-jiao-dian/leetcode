class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (const auto& oper : operations){
            for (char a : oper){
                if (a == '+'){
                    ++x; break;
                }
                if (a == '-'){
                    --x; break;
                }
            }
        }
        return x;
    }
};