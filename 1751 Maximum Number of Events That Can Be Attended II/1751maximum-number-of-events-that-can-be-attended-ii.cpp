class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        std::sort(events.begin(), events.end(), [](const auto &ev1, const auto &ev2) {
            if (ev1[1] == ev2[1]) {
                return ev1[0] < ev2[0];
            }

            return ev1[1] < ev2[1];
        });

        std::vector<std::vector<int>> dp(events.size()+1, std::vector<int>(k+1, 0));
        std::vector<int> prefix(events.size(), -1);
        for (int i = 1; i < prefix.size(); ++i) {
            prefix[i] = bs(events, i);
        }
        for (int i = 1; i <= events.size(); ++i) {
            for (int c = 1; c <= k; ++c) {
                int j = prefix[i-1];
                dp[i][c] = std::max(dp[i-1][c], events[i-1][2] + dp[j+1][c-1]);
            }
        }

        return dp[events.size()][k];
    }

    int bs(const vector<vector<int>>& events, int i) { 
        int low = 0;
        int high = i-1;
        int mid = high / 2;
        int result = -1;
        while (low <= high) {
            if (events[mid][1] < events[i][0]) {
                result = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
            mid = (low + high) / 2;
        }

        return result;
    }
};