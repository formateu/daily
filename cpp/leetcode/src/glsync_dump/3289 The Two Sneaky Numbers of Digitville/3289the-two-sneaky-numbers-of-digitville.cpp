class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        std::array<int, 101> occ{};
        for (const auto &i : nums) {
            ++occ[i];
        }

        std::vector<int> result;
        for (int i = 0; i < occ.size(); ++i) {
            if (occ[i] > 1) result.emplace_back(i);
        }

        return result;
    }
};