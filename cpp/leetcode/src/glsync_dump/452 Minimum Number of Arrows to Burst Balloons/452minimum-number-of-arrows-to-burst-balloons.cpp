#include <algorithm>

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const auto &lhs, const auto &rhs) {
            if (lhs[0] == rhs[0]) {
                return lhs[1] < rhs[1];
            } else return lhs[0] < rhs[0];
        });

        std::vector<int> common, last;
        int result = 0;
        for (const auto &p: points) {
            if (!last.size()) {
                last = p;
                common = p;
                ++result;
                continue;
            }

            //overlap with current common
            if (common[1] >= p[0]) {
                common[1] = std::min(common[1], p[1]);
                common[0] = p[0];
                last = p;
                // result stays the same
            } else {
                ++result;
                common[0] = p[0];
                common[1] = p[1];
            }
        }

        return result;
    }
};