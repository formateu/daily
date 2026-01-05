class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        int smallestMod = std::numeric_limits<int>::max();
        int negatives = 0;
        long long result = 0;
        bool hasZeros = false;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!hasZeros && matrix[i][j] == 0) {
                    hasZeros = true;
                    continue;
                } else if (matrix[i][j] < 0) {
                    ++negatives;
                }

                int m = std::abs(matrix[i][j]);
                if (smallestMod > m) {
                    smallestMod = m;
                }
                result += m;
            }
        }

        if (!hasZeros && negatives % 2) {
            result -= 2*smallestMod;
        }

        return result;
    }
};