class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = grid.size() - 1; i >= 0; --i) {
            for (int j = grid[0].size() - 1; j >= 0; --j) {
                if (grid[i][j] < 0) ++result;
                else break;
            } 
        }

        return result;
    }
};