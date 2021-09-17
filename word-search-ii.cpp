struct TrieNode {
    string word;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        this->word = "";
    }
};

void insertTrie(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for(auto c: word) {
        if(!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->word = word;
}


class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(vector<vector<char>>& board, int x, int y, TrieNode* root, vector<string>& ans) {
        char c = board[x][y];
        if(!root->children.count(c)) {
            return false;
        }
        TrieNode* nxt = root->children[c];
        if(nxt->word != "") {
            ans.emplace_back(nxt->word);
            nxt->word = "";
        }
        board[x][y] = '#';
        for(int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                dfs(board, nx, ny, nxt, ans);
            }
        }
        board[x][y] = c;
        if(nxt->children.empty()) {
            root->children.erase(c);
        }
        return true;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        TrieNode *root = new TrieNode();
        for(auto& word: words){
            insertTrie(root, word);
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, ans);
            }
        }
        return ans;
    }
};