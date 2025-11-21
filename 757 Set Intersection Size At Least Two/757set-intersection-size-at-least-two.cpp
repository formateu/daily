class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const auto &i1, const auto &i2) {
            if (i1[1] == i2[1]) {
                return i1[0] > i2[0];
            }

            return i1[1] < i2[1];
        });

        int p1 = -1, p2 = -1, result = 0;
        for (const auto &i : intervals) {
            if (p1 >= i[0] && p1 <= i[1] && p2 >= i[0] && p2 <= i[1]) continue;
            if (p1 >= i[0] && p1 <= i[1]) {
                p2 = i[1];
                ++result;
            } else if (p2 >= i[0] && p2 <= i[1]) {
                p1 = i[1];
                ++result;
            } else {
                p2 = i[1];
                p1 = i[1] - 1;
                result += 2;
                continue;
            }
        }

        return result;
    }
};