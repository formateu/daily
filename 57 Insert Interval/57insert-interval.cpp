class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> output;
        if (!intervals.size()) {
            output.emplace_back(newInterval);
            return output;
        }

        output.reserve(intervals.size());
        for (auto it = intervals.begin(); it != intervals.end();) {
            auto &interval = newInterval.size() ? std::min(*it, newInterval) : *it;

            if (!output.size()) {
                output.emplace_back(interval);

                if (interval == newInterval) {
                    newInterval.clear();
                } else {
                    ++it;
                }

                continue;
            }

            auto &back = output.back();

            if (back[1] < interval[0]) {
                output.emplace_back(interval);
            } else if (back[1] >= interval[0] && back[1] < interval[1]) {
                back[1] = interval[1];
            }

            if (interval == newInterval) {
                newInterval.clear();
            } else {
                ++it;
            }
        }

        if (newInterval.size()) {
            auto &back = output.back();

            if (back[1] < newInterval[0]) {
                output.emplace_back(newInterval);
            } else if (back[1] >= newInterval[0] && back[1] < newInterval[1]) {
                back[1] = newInterval[1];
            }
        }

        return output;
    }
};