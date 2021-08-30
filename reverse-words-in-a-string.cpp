class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        string word = "";
        for (int i = 0; i <= s.length(); ++i){
            char temp = s[i];
            if (temp == ' ' && word != "" || i == s.length()){
                words.push(word);
                word = "";
            } else if (temp != ' ') {
                word.push_back(temp);
            }
        }
        string res = "";
        while (!words.empty()){
            if (words.top()[0] == '\0'){
                words.pop(); continue;
            }
            if (words.top()[0] != ' '){
                res += words.top();
                words.pop();
                res += " ";
            } else {
                break;
            }
        }
        int i;
        for (i = res.length() - 1; i >= 0; --i)
            if (res[i] != ' ')
                break;
        res = res.substr(0, i + 1);
        return res;
    }
};