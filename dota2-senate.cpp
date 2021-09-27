class Solution {
public:
    string predictPartyVictory(string senate) {
        int r = 1, d = 1, cr = 1, cd = 1;
        while (cr && cd){
            string s = "";
            cr = 0, cd = 0;
            for (char se : senate){
                if (se == 'R'){
                    cr = 1;
                    if (r > 0) s += 'R', --d;
                    else ++r;
                } else {
                    cd = 1;
                    if (d > 0) s += 'D', --r;
                    else ++d;
                }
            }
            senate = s;
        }
        if (senate[0] == 'R') return "Radiant";
        return "Dire";
    }
};