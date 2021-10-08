class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int p1 = 0, p2 = 0;
        size_t len1 = name.size(), len2 = typed.size();
        while (p1 < len1 && p2 < len2){
            if (name[p1] != typed[p2]) return 0;
            while (p1 < len1 && p2 < len2 && name[p1] == typed[p2]){
                ++p1, ++p2;
            }
            char temp = name[p1 - 1];
            while (p2 < len2 && typed[p2] == temp){
                ++p2;
            }
        }
        if (p1 < len1) return 0;
        char temp = name.back();
        while (p2++ < len2) if (typed[p2] != temp) return 0;
        return 1;
    }
};