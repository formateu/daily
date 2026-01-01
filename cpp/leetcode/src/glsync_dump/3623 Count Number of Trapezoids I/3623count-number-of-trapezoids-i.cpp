class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int MOD = 1'000'000'007;
        const int N = points.size();
        // sort Y
        std::sort(points.begin(), points.end(), [](const auto &p1, const auto &p2) {
            return p1[1] < p2[1];
        });

        std::int64_t result = 0;
        std::int64_t sumPairs = 0;
        for (int i = 0; i < N;) {
            int j = i;
            while (j < N && points[j][1] == points[i][1]) ++j;
            if (j-i > 1) {
                const std::int64_t w = j-i;
                std::int64_t possibilities = (w * (w-1) / 2) % MOD;
                result = (result + sumPairs * possibilities) % MOD;
                sumPairs = (sumPairs + possibilities) % MOD;
                i = j;
            } else {
                ++i;
            }
        }

        return result;
    }
};