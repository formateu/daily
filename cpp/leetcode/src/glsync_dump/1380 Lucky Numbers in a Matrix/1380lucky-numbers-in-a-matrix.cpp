class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        std::vector<int> minRow(matrix.size(), std::numeric_limits<int>::max());
        std::vector<int> maxCol(matrix[0].size(), std::numeric_limits<int>::min());

        for (int i = 0; i < matrix.size(); ++i) {
            minRow[i] = *std::ranges::min_element(matrix[i]);
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                maxCol[j] = std::max(maxCol[j], matrix[i][j]);
            }
        }

        std::vector<int> luckyNumbers;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]) {
                    luckyNumbers.emplace_back(matrix[i][j]);
                }
            }
        }

        return luckyNumbers;
    }
};