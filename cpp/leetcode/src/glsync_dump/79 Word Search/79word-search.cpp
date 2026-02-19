class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (this->dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>> &board, const std::string &word, short i, short j, short pos) {
        if (pos == word.size()) {
            return true;
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[pos]) {
            return false;
        }

        char ch = board[i][j];
        board[i][j] = '/';

        if (this->dfs(board, word, i-1, j, pos+1) || this->dfs(board, word, i+1, j, pos+1) || this->dfs(board, word, i, j-1, pos+1) || this->dfs(board, word, i, j+1, pos+1)) {
            return true;
        }

        board[i][j] = ch;
        return false;
    }

};