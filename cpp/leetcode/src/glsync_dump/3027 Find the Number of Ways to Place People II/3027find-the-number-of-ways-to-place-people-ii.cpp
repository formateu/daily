class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        const int N = points.size();
        std::sort(points.begin(), points.end(), [](const auto &lhs, const auto &rhs) {
            if (lhs[0] == rhs[0]) {
                return lhs[1] > rhs[1];
            }

            return lhs[0] < rhs[0];
        });

        int result = 0;
        for (int i = 0; i < N; i++) {
            int max_y = std::numeric_limits<int>::min();
            int upper_y = points[i][1];
            for (int j = i + 1; j < N; j++) {
                if (points[j][1] <= upper_y && points[j][1] > max_y) {
                    result++;
                    max_y = points[j][1];
                }
            }
        }
        return result;
    }
};