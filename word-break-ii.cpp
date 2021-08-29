class Solution {
private:
    vector<string> res;
    vector<int> temp;
    size_t len;
    int miniLen;

public:
    void sentence(string s, set<string> wordSet, int pos, int pre){
        if (pos == len){
            string ans = s;
            int flag = 1;
            for (int t : temp){
                ans.insert(t + flag, " ");
                ++flag;
            }
            ans[ans.length() - 1] = '\0';
            res.emplace_back(ans);
            return;
        }
        for (int i = pos; i < len; ++i){
            int flag = 0;
            if (pre == -1 && inDic(s.substr(0, i + 1), wordSet)) flag = 1;
            else if (pre != -1 && inDic(s.substr(pre + 1, i - pre), wordSet)) flag = 1;
            if (flag){
                temp.emplace_back(i);
                sentence(s, wordSet, i + 1, i);
                temp.pop_back();
            }
        }
    }

     int inDic(string s, set<string>& wordSet){
        if (wordSet.find(s) != wordSet.end()) return 1;
        return 0;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        len = s.length();
        sentence(s, wordSet, 0, -1);
        return res;
    }
};