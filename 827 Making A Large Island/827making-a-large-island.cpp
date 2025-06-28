class Solution {
    using Grid = vector<vector<int>>;
public:
    int largestIsland(Grid& grid) {
        int currentGroup = 2;
        std::unordered_map<int, int> groups;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    groups.emplace(currentGroup, exploreIsland(currentGroup, i, j, grid));
                    ++currentGroup;
                }
            }
        }

        int best = 0;
        for (auto const& [id, sz] : groups) 
            best = std::max(best, sz);        
        
        std::unordered_set<int> neigh;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    if (i + 1 < grid.size() && grid[i+1][j] > 1) {
                        neigh.emplace(grid[i+1][j]);
                    }

                    if (j + 1 < grid[0].size() && grid[i][j+1] > 1) {
                        neigh.emplace(grid[i][j+1]);
                    }

                    if (i - 1 >= 0 && grid[i-1][j] > 1) {
                        neigh.emplace(grid[i-1][j]);
                    }

                    if (j - 1 >= 0 && grid[i][j-1] > 1) {
                        neigh.emplace(grid[i][j-1]);
                    }

                    int neighSum = 1; 
                    for (int grpId : neigh)
                        neighSum += groups[grpId];

                    best = std::max(best, neighSum);

                    neigh.clear();
                }
            }
        }

        return best; 
    }

    int exploreIsland(int currentGroup, int i, int j, Grid &grid) {
        int size = 0;
        std::vector<std::pair<int, int>> queue;
        queue.emplace_back(i, j);

        while (!queue.empty()) {
            const auto [x, y] = queue.back();
            queue.pop_back();
            if (grid[x][y] != 1) continue;
            grid[x][y] = currentGroup;
            ++size;

            if (x + 1 < grid.size() && grid[x+1][y] == 1) {
                queue.emplace_back(x+1, y);
            }

            if (y + 1 < grid[0].size() && grid[x][y+1] == 1) {
                queue.emplace_back(x, y+1);
            }

            if (x - 1 >= 0 && grid[x-1][y] == 1) {
                queue.emplace_back(x - 1, y);
            }

            if (y - 1 >= 0 && grid[x][y-1] == 1) {
                queue.emplace_back(x, y - 1);
            }
        }

        return size;
    }
};