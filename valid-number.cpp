class Solution {
public:
    bool isNum(char temp){
        return temp >= '0' && temp <= '9';
    }

    bool integer(string s){
        int start = 0;
        size_t len = s.size();
        if (!len) return 0;
        if (s[0] == '+' || s[0] == '-') ++start;
        else if (!isNum(s[0])) return 0;
        if (start >= len) return 0;

        for (int i = start; i < len; ++i){
            if (!isNum(s[i])) return 0;
        }
        return 1;
    }

    bool decimal(string s){
        int start = 0;
        size_t len = s.size();
        if (!len) return 0;
        if (s[0] == '+' || s[0] == '-' || s[0] == '.') ++start;
        else if (!isNum(s[0])) return 0;
        if (start >= len) return 0;

        int i;
        if (s[0] == '.') i = 0;
        else {
            for (i = start; i < len; ++i){
                if (s[i] == '.'){
                    if (s[0] == '.') return 0;
                    else break;
                }
                if (!isNum(s[i])) return 0;
            }
        }
        
        string pre = s.substr(start, i - start);
        string suc = i == len ? "" : s.substr(i + 1, len - i - 1);
        if (i < len - 1 && !isNum(s[i + 1])) return 0;
        if (i != len && (integer(pre) || pre == "") && (integer(suc) || i == len - 1 && suc == "" && pre != "")) return 1;
        return 0;
    }

    bool isNumber(string s) {
        size_t len = s.size();
        int i;
        for (i = 0; i < len; ++i){
            if (s[i] == 'e' || s[i] == 'E') break;
        }
        string pre = s.substr(0, i);
        string suc = i == len ? "" : s.substr(i + 1, len - i - 1);
        if (i != len && (decimal(pre) || integer(pre)) && integer(suc)) return 1;
        if (i == len && (decimal(pre) || integer(pre))) return 1;
        return 0;
    }
};