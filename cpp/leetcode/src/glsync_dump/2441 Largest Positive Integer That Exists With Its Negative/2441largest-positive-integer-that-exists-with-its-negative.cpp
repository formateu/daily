class Solution {
public:
    int findMaxK(vector<int>& nums) {
        std::unordered_set<int> lookup(nums.begin(), nums.end());
        int max = 0;
        for (const auto &e: lookup) {
            if (lookup.contains(-1 * e) && abs(e) > max) {
                max = abs(e);
            }
        }

        return max == 0 ? -1 : max;
    }
};