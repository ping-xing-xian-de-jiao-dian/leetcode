class Solution {
public:
    map<int, string> mp1 = {{0,""}, {1,"One"}, {2,"Two"}, {3,"Three"}, {4,"Four"}, {5,"Five"}, {6,"Six"}, {7,"Seven"}, {8,"Eight"}, {9,"Nine"}, {10,"Ten"}, {11,"Eleven"}, {12,"Twelve"}, {13,"Thirteen"}, {14,"Fourteen"}, {15,"Fifteen"}, {16,"Sixteen"}, {17,"Seventeen"}, {18,"Eighteen"}, {19,"Nineteen"}};
    map<int, string> mp2 = {{2,"Twenty"}, {3,"Thirty"}, {4,"Forty"}, {5,"Fifty"}, {6,"Sixty"}, {7,"Seventy"}, {8,"Eighty"}, {9,"Ninety"}};
    vector<string> vec = {"Hundred", "Thousand", "Million", "Billion"};

    string numberToWords(int num) {
        if (!num) return "Zero";
        stack<string> s;
        int pos = 1;
        while (num){
            int temp = num % 1000;
            if (temp){
                int end2 = temp % 100;
                if (end2 >= 20){
                    if (end2 % 10) s.push(mp1[end2 % 10]);
                    s.push(mp2[end2 / 10]);
                } else if (end2) {
                    s.push(mp1[end2]);
                }
                if (temp / 100 > 0) s.push(vec[0]), s.push(mp1[temp / 100]);
            } else if (!s.empty()) s.pop();
            num /= 1000;
            if (num) s.push(vec[pos]);
            pos = pos % 3 + 1;
        }
        string res = "";
        while (!s.empty()){
            res += s.top();
            s.pop();
            if (!s.empty()) res += " ";
        }
        return res;
    }
};