class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        std::vector<std::pair<int, int>> intervals;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == key) {
                const int newRight = std::min(static_cast<int>(nums.size() - 1), i + k);
                const int newLeft = std::max(0, i - k);
                if (!intervals.empty() && intervals.back().second >= newLeft) {
                    intervals.back().second = newRight;
                } else {
                     intervals.emplace_back(newLeft, newRight);
                }
            }
        }
        std::vector<int> result;
        for (const auto &[l, r] : intervals) {
            for (int i = l; i <= r; ++i) {
                result.emplace_back(i);
            }
        }
        

        return result;
    }
};