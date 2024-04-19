class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        std::vector<std::pair<int16_t, int16_t>> stack;
        stack.reserve(grid.size() * grid[0].size());
        int numberOfIslands = 0;

        for (int16_t i = 0; i < grid.size(); ++i) {
            for (int16_t j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++numberOfIslands;
                    stack.emplace_back(i,j);
                    markIsland(grid, stack);
                }
            }
        }

        return numberOfIslands;
    }

    void markIsland(vector<vector<char>>& grid, std::vector<std::pair<int16_t, int16_t>> &stack) {
        while (!stack.empty()) {
            auto [x,y] = stack.back();
            stack.pop_back();
            grid[x][y] = 'X';
            addNeighbourToCheckIfIsland(grid, stack, x-1, y);
            addNeighbourToCheckIfIsland(grid, stack, x, y-1);
            addNeighbourToCheckIfIsland(grid, stack, x+1, y);
            addNeighbourToCheckIfIsland(grid, stack, x, y+1);
        }
    }

    bool checkIfProperLand(const vector<vector<char>>& grid, int16_t i, int16_t j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == '1';
    }

    void addNeighbourToCheckIfIsland(const vector<vector<char>>& grid, std::vector<std::pair<int16_t, int16_t>> &stack, int16_t i, int16_t j) {
        if (checkIfProperLand(grid, i, j)) {
            stack.emplace_back(i, j);
        }
    }
};