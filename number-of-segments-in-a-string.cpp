class Solution {
public:
    int countSegments(string s) {
        char pre = ' ';
        int cou = 0;
        for (char temp : s){
            if (temp != ' ' && pre == ' '){
                ++cou; pre = temp;
            } else {
                pre = temp;
            }
        }
        return cou;
    }
};