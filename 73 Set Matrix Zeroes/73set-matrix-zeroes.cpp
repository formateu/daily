class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const auto M = matrix.size();
        const auto N = matrix.front().size();
    
        bool firstColZero = false;
        for (int i = 0; i < M; ++i) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
            }

            for (int j = 1; j < N; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = M - 1; i >= 0; --i) {
            for (int j = N-1; j > 0; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }

            if (firstColZero) {
                matrix[i][0] = 0;
            }
        }
    }
};