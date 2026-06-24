class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        string word;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
            word = "";
        }
    };

    TrieNode* root = new TrieNode();

    void insert(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->child[idx] == NULL)
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node,
             vector<string>& ans) {

        char ch = board[i][j];

        if (ch == '#' || node->child[ch - 'a'] == NULL)
            return;

        node = node->child[ch - 'a'];

        if (node->word != "") {
            ans.push_back(node->word);
            node->word = "";   // avoid duplicates
        }

        board[i][j] = '#';

        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        for (auto &d : dir) {
            int x = i + d[0];
            int y = j + d[1];

            if (x >= 0 && y >= 0 &&
                x < board.size() && y < board[0].size()) {
                dfs(board, x, y, node, ans);
            }
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        for (string &w : words)
            insert(w);

        vector<string> ans;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
};