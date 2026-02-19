class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        std::vector<std::vector<int>> grid(row, std::vector<int>(col, 0));
        std::vector<int> fifo;
        std::vector<int> visited(row*col, -1);
        fifo.reserve(row * col);
        int prevTarget = 0;
        int stamp = 0;

        int lo = 0, hi = cells.size();
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            apply(cells, grid, prevTarget, mid);
            if (bfs(grid, fifo, visited, row, col, stamp)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
            ++stamp;
        }

        return lo;
    }

    void apply(const vector<vector<int>>& cells, vector<vector<int>>& grid, int &prevTarget, int target) {
        if (target > prevTarget) {
            for (int i = prevTarget; i < target; ++i) {
                const int r = cells[i][0] - 1;
                const int c = cells[i][1] - 1;
                grid[r][c] = 1;
            }
        } else {
            for (int i = target; i < prevTarget; ++i) {
                const int r = cells[i][0] - 1;
                const int c = cells[i][1] - 1;
                grid[r][c] = 0;
            }
        }

        prevTarget = target;
    }

    bool bfs(const vector<vector<int>>& grid, std::vector<int> &fifo, std::vector<int> &visited, int row, int col, int stamp) {
        fifo.clear();
        int index = 0;
        for (int i = 0; i < col; ++i) {
            if (grid[0][i] == 0) {
                fifo.emplace_back(i);
                visited[i] = stamp;
            }
        }

        while (index < fifo.size()) {
            int id = fifo[index];
            int c = id % col;
            int r = id / col;

            if (r == row - 1) {
                return true;
            }

            if (int x1 = (r+1) * col + c; r + 1 < row && grid[r+1][c] == 0 && visited[x1] != stamp) {
                fifo.emplace_back(x1);
                visited[x1] = stamp;
            }
            if (int x1 = (r-1) * col + c; r - 1 >= 0 && grid[r-1][c] == 0 && visited[x1] != stamp) {
                fifo.emplace_back(x1);
                visited[x1] = stamp;

            }
            if (int x1 = r*col + (c+1); c + 1 < col && grid[r][c+1] == 0 && visited[x1] != stamp) {
                fifo.emplace_back(x1);
                visited[x1] = stamp;
            }
            if (int x1 = r*col + (c-1); c - 1 >= 0 && grid[r][c-1] == 0 && visited[x1] != stamp) {
                fifo.emplace_back(x1);
                visited[x1] = stamp;

            }

            ++index;
        }

        return false;
    }
};