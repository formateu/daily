class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int a, b, c, d;
        std::vector<std::vector<int>> intersections;
        intersections.reserve( firstList.size());
        for (int i = 0, j = 0; i < firstList.size() && j < secondList.size();) {
            const auto &curF = firstList[i];
            const auto &curS = secondList[j];
            const int a = curF.front(), b = curF.back();
            const int c = curS.front(), d = curS.back();

            if (a <= c) {
                if (b < c) {
                    ++i;
                } else if (b <= d) {
                    intersections.emplace_back(std::vector<int>{c, b});
                    ++i;
                } else {
                    intersections.emplace_back(std::vector<int>{c, d});
                    ++j;
                }
            } else {
                if (d < a) {
                    ++j;
                } else if (b <= d) {
                    intersections.emplace_back(std::vector<int>{a, b});
                    ++i;
                } else {
                    intersections.emplace_back(std::vector<int>{a, d});
                    ++j;
                }
            }
        }

        return intersections;
    }
};