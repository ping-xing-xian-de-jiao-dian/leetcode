class TrieTree{
public:
    char val;
    int end;
    map<char, TrieTree*> nxt;

    TrieTree(char val){
        this->val = val;
        end = 0;
    }
};

class WordDictionary {
private:
    TrieTree* words;

public:
    WordDictionary() {
        words = new TrieTree(' ');
    }
    
    void addWord(string word) {
        TrieTree* temp = words;
        for (char w : word){
            if (!temp->nxt.count(w)){
                temp->nxt[w] = new TrieTree(w);
            }
            temp = temp->nxt[w];
        }
        temp->end = 1;
    }
    
    bool dfs(TrieTree* temp, string word, int pos){
        if (!temp) return 0;
        if (pos == word.size()){
            return temp->end;
        }
        char w = word[pos];
        if (w == '.'){
            int flag = 0;
            for (auto& [k, v] : temp->nxt){
                if (dfs(v, word, pos + 1)){
                    flag = 1; break;
                }
            }
            return flag;
        } else {
            return dfs(temp->nxt[w], word, pos + 1);
        }
    }

    bool search(string word) {
        TrieTree* temp = words;
        return dfs(temp, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */