class Solution {
public:
    int countUnguarded(int m, int n, std::vector<std::vector<int>>& guards, std::vector<std::vector<int>>& walls) {
        std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));
        for (const auto &g: guards) {
            const auto i = g[0];
            const auto j = g[1];
            grid[i][j] = 1;
        }

        for (const auto &w: walls) {
            const auto i = w[0];
            const auto j = w[1];
            grid[i][j] = 2;
        }

        for (const auto &g: guards) {
            const auto gi = g[0];
            const auto gj = g[1];
            if (gj < n) {
                int j = gj+1;
                while (j < n && grid[gi][j] < 1) {
                    grid[gi][j] = -1;
                    ++j;
                }
            }

            if (gi < m) {
                int i = gi+1;
                while (i < m && grid[i][gj] < 1) {
                    grid[i][gj] = -1;
                    ++i;
                }
            }

            if (gj > 0) {
                int j = gj-1;
                while (j >= 0 && grid[gi][j] < 1) {
                    grid[gi][j] = -1;
                    --j;
                }
            }

            if (gi > 0) {
                int i = gi-1;
                while (i >= 0 && grid[i][gj] < 1) {
                    grid[i][gj] = -1;
                    --i;
                }
            } 
        }

        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++result;
                }
            }
        }

        return result;     
    }
};

static const auto fast_io = []() noexcept {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();