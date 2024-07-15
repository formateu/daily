class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long result = 0;
        for (int16_t i = 0, prevEnd = 0; i < customers.size(); ++i) {
            const auto &start = customers[i][0];
            const auto &time = customers[i][1];
            const auto end = max(start, prevEnd) + time;
            result += (end - start);
            prevEnd = end;
        }

        return result / static_cast<double>(customers.size());
    }
};