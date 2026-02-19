class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int result = 0;
        for (int i = 0; i <= k; ++i) {
            result += tickets[k];

            if (tickets[i] < tickets[k]) {
                result -= tickets[k] - tickets[i];
            }
        }

        for (int i = k+1; i < tickets.size(); ++i) {
            result += tickets[k]-1;

            if (tickets[i] < tickets[k]) {
                result -= tickets[k] - tickets[i] - 1;
            }
        }

        return result;
    }
};