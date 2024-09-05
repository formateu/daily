class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        const int sum = std::accumulate(rolls.begin(), rolls.end(), 0);
        const int remaining = mean*(n+rolls.size()) - sum;
        const int even = remaining / n;
        if (even > 6 || (even == 6 && remaining % n) || remaining < 0 || remaining < n) {
            return {};
        }

        std::vector<int> missing(n, even);
        int missingSum = std::accumulate(missing.begin(), missing.end(), 0);
        if (missingSum < remaining)  {
            int currI = 0;
            while (missingSum < remaining && currI < n) {
                int delta = remaining - missingSum;
                if (missing[currI] < 6) {
                    const int diff = std::min(6 - missing[currI], delta);
                    missing[currI] += diff;
                    missingSum += diff;
                    delta -= diff;
                }
                ++currI;
            }
        }

        return missing;
    }
};

static const int kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();