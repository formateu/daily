class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        constexpr int MAX_MASK = 25;
        int maxResult = 0;

        for (int i = 0; i < MAX_MASK; ++i) {
            const int mask = 1 << i;
            int result = 0;
            for (const auto &c: candidates) {   
                if (int bit = c & mask; bit) {
                    ++result;
                }
            }
            maxResult = std::max(maxResult, result);
        }

        return maxResult;
    }
};