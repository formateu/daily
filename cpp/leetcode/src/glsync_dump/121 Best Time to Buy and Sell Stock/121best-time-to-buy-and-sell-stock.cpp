class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentMin = prices[0];

        int best = 0;

        for (int i = 1; i < prices.size(); ++i) {
            best = std::max(best, prices[i] - currentMin);
            if (prices[i] < currentMin) {
                currentMin = prices[i];
            }
        }

        return best;
    }
};