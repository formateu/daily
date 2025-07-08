class Solution {
public:
    void solve(vector<vector<char>>& board) {
        char color = 0;
        std::unordered_set<int> bad;

        const int M = board.size();
        const int N = board.front().size();

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == 'O') {
                    const bool isBad = explore(board, i, j, M, N, color);
                    if (isBad) {
                        bad.emplace(color);
                    }
                    ++color;
                }
            }
        }

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] != 'X') {
                    if (!bad.contains(board[i][j])) {
                        board[i][j] = 'X';
                    } else {
                        board[i][j] = 'O';
                    }
                }
            }
        }
    }

    
    bool explore(vector<vector<char>>& board, int i, int j, const int M, const int N, char color) {
        std::queue<std::pair<int, int>> pq;
        pq.emplace(i, j);

        bool result = false;
        while (!pq.empty()) {
            auto [x, y] = pq.front();
            pq.pop();
            if (board[x][y] != 'O') continue;

            board[x][y] = color;
            if (!result) {
                if (x == 0 || x == M-1) {
                    result = true;
                }
                if (y == 0 || y == N-1) {
                    result = true;
                }
            }


            if (x+1 < M && board[x+1][y] == 'O') pq.emplace(x+1, y);
            if (x-1 >= 0 && board[x-1][y] == 'O') pq.emplace(x-1, y);
            if (y+1 < N && board[x][y+1] == 'O') pq.emplace(x, y+1);
            if (y-1 >= 0 && board[x][y-1] == 'O') pq.emplace(x, y-1);
        }

        return result;
    }
};